#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree; //! Дерево
vector<int> branch_sum; //! Суммы на здоровых ветках (полные суммы)
vector<int> branch_sum_infected; //! Суммы на зараженных ветках (спасаем по максимуму)
int n;

/**
 * Это dfs для подсчета сумм веток, буд-то бы они все здоровы
*/
void dfs_sum(int point, int parrent){
    // parrent мне мешает - удалю его (это не очень хорошая практика, но по BigO могу себе позволить)
    tree[point].erase(remove(tree[point].begin(), tree[point].end(), parrent), tree[point].end());
    for (auto child : tree[point]){
        dfs_sum(child, point);
        branch_sum[point] += branch_sum[child];
    }
}

/**
 * Это dfs для подсчета сумм с учетом заражения
*/
void dfs_answer(int point){
    // Если идти некуда - спасать нечего
    if (tree[point].size() == 0)
        return;
    // Если путь один - его и изолируем
    if (tree[point].size() == 1){
        branch_sum_infected[point] = branch_sum[tree[point][0]] - 1;
        return;
    }

    /* Иначе веток две - есть два выбора:
    1. Изолируем левую, пропускаем инфекцию на правую
    2. Изолируем правую, пропускаем инфекцию на левую
       Выбор зависит от того, каким способом больше вершин спасем */
    int left_child = tree[point][0];
    int right_child = tree[point][1];
    dfs_answer(left_child);
    dfs_answer(right_child);
    branch_sum_infected[point] = max(branch_sum[left_child]-1 + branch_sum_infected[right_child],
                                     branch_sum[right_child]-1 + branch_sum_infected[left_child]);
}

void reset_values(){
    tree.clear();
    tree.resize(n + 1);
    branch_sum.clear();
    branch_sum.resize(n + 1, 1);
    branch_sum_infected.clear();
    branch_sum_infected.resize(n + 1, 0);
}

void solve(){
    cin >> n;
    reset_values();
    
    while(n-- > 1){
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    dfs_sum(1, -1);
    dfs_answer(1);

    cout << branch_sum_infected[1] << '\n';
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
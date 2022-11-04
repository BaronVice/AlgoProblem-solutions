/* Идея задачи: вместо подсчета сумм в каждом запросе, посчитаем их сразу (префиксные суммы)
Будет два массива префиксных сумм: для первого запроса при упорядоченном порядке камней
и для второго запроса, где камни расположены по возрастанию стоимости (используем сортировку) */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
int main(){

    int n;
    cin >> n;
    vector <ll> costs(n);
    for (auto &i : costs){
        cin >> i;
    }
    // Префиксные суммы для первого запроса
    vector <ll> prefSumCosts(n + 1, 0);
    for (int i = 0; i < n; i++){
        prefSumCosts[i + 1] = prefSumCosts[i] + costs[i]; 
    }

    // Сортируем стоимости для составления префиксных сумм к второму запросу
    sort(costs.begin(), costs.end());
    // Префиксные суммы для второго запроса
    vector <ll> sortedPrefSumCosts(n + 1, 0);
    for (int i = 0; i < n; i++){
        sortedPrefSumCosts[i + 1] = sortedPrefSumCosts[i] + costs[i]; 
    }

    // Количество запросов, тип запроса, начало отрезка, конец отрезка
    int q, request, left, right;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> request >> left >> right;
        /*
        Вобще формула выглядит следующим образом:
        prefSum[right + 1] - prefSum[left]

        Но нужно учесть, что left и right задаются с единицы, но индексация начинается с нуля,
        поэтому здесь:
        prefSum[right + 1 - 1] - prefSum[left - 1] -> prefSum[right] - prefSum[left - 1]
        */
        if (request == 1){
            cout << prefSumCosts[right] - prefSumCosts[left - 1] << endl;
        }
        else{
            cout << sortedPrefSumCosts[right] - sortedPrefSumCosts[left - 1] << endl;
        }
    }

    return 0;
}
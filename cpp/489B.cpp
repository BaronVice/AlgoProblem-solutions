/* Идея задачи: задача про сортировку и два указателя - сперва соритруем массив умений юношей
и умений девушек. Далее задаем два указателя (на массив юношей и девушек соответственно) и
проходим через них до тех пор, пока не дойдем до конца какого-нибудь списка. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector <int> men(n);
    for (auto &i : men){
        cin >> i;
    }

    int m;
    cin >> m;
    vector <int> women(m);
    for (auto &i : women){
        cin >> i;
    }
    // Применяем сортировку
    sort(men.begin(), men.end());
    sort(women.begin(), women.end());
    // Даем два указателя: p1 - для юношей, p2 - для девушек  
    int p1 = 0, p2 = 0, result = 0;
    // Пока не достигли конца одного из массивов
    while (p1 < n && p2 < m){
        // Если разность умений по модулю меньше равно одному, то пара есть рассматриваем следующую
        if (abs(men[p1] - women[p2]) <= 1){
            result++;
            p1++;
            p2++;
        }
        // Иначе перемещаем один из указателей, в зависимости от того, кто менее скиловый
        else {
            men[p1] < women[p2] ? p1++ : p2++;
        }
    }

    cout << result;

    return 0;
}
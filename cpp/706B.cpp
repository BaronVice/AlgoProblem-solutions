/* Идея задачи: сортировка + бинарный поиск. Сперва сортируем массив цен по возрастанию, после
находим первый слева элемента в массиве, который будет больше суммы монет в запросе. Индекс
этого элемента и будет ответом */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;

    vector <int> costs(n);
    for (auto &i : costs){
        cin >> i;
    }

    int q;
    cin >> q;
    ll money;
    for (int i = 0; i < q; i++){
        cin >> money;
        // Вместо бинарного поиска воспользуемся upper_bound, который найдет первый слева
        // индекс элемента в массиве, что такой элемент будет больше заданного 
        cout << upper_bound(costs.begin(), costs.end(), money) - costs.begin() << endl;
    }

    return 0;
}
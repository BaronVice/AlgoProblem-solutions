/* Идея задачи: поскольку в письме не указывается номер квартиры в конкретном общежитии, но
номер квартиры среди всех n общежитий, то для определения номера общежития посчитаем сумму
квартир с учетом предыдущих общежитий (префиксные суммы). Далее для каждого письма ищем такую
сумму, чтобы значение письма было меньше или равно первой встреченной слева сумме  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto &i : a){
        cin >> i;
    }

    vector<ll> prefSum(n + 1, 0);
    for (int i = 0; i < n; i++){
        prefSum[i + 1] = prefSum[i] + a[i];
    }

    ll letter, number, room;
    for (int i = 0; i < m; i++){
        cin >> letter;

        // lower_bound - чтобы не писать бинарный поиск:
        // Ищет первый слева элемент массива, который будет больше или равен заданному элементу
        number = lower_bound(prefSum.begin(), prefSum.end(), letter) - prefSum.begin();
        room = letter - prefSum[number - 1];
        
        cout << number << ' ' << room << endl;
    }

    return 0;
}
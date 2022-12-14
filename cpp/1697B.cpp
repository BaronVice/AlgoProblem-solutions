/* Идея задачи: максимальная суммарная стоимости бесплатных товаров достигается если из всех
товаров брать самые дорогие (т.е. в запросах из X самых дорогих товаров берем Y самых дешевых,
это и будет ответом). Также здесь стоит воспользоваться решением через префиксные суммы, посколку
считать сумму бесплатных товаров для каждого запроса будет слишком долго */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vector <ll> prices(n);
    for(auto &i : prices){
        cin >> i;
    }
    // Сортируем массив цен по убыванию (от наибольшего к наименьшему, чтобы брать первые X максимальных)
    sort(prices.rbegin(), prices.rend());
    // Находим префиксные суммы цен
    for(int i = 0; i < n - 1; i++){
        prices[i + 1] += prices[i];
    }

    int x, y;
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        /* Если все X купленных товаров нам отдадут бесплатно, то вывод суммы элементов до X
        (ответом будет X самых дорогих товаров) */
        if (x == y){
            cout << prices[x - 1];
        }
        /* Иначе сумма элементов до позиции X минус сумма элементов до позиции X-Y
        (здесь ответ находим из X самых дорогих товаров берем Y самых дешевых) */
        else{
            cout << prices[x - 1] - prices[x - y - 1];
        }
        // P.S. не забываем про -1 в индексах, поскольку мы считаем с нуля
        cout << '\n';
    }

    return 0;
}
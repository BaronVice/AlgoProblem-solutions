// Идея задачи: бинарный поиск по формуле

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// Функция, с которой будем определять минимальную стоимость при выбранном k товаров
ll countCost(ll pickedValue, vector<ll>& costs, ll n) {
    vector <ll> newCosts;
    // Получаем новые стоимости в соответствии с формулой
    for (ll i = 0; i < n; i++)
        newCosts.push_back(costs[i] + (i + 1) * pickedValue);
    // Чтобы взять первые pickedValue минимальных значений, отсортируем массив стоимостей
    // По возрастанию (от наименьшего к наибольшему)
    sort(newCosts.begin(), newCosts.end());

    // Считаем сумму первых picked_k товаров
    ll result = 0;
    for (int i = 0; i < pickedValue; i++)
        result += newCosts[i];

    return result;
}


int main() {
    ll n, S;
    cin >> n >> S;

    vector <ll> costs(n);
    for (auto& i : costs) {
        cin >> i;
    }

    // Изначально k и T равны 0
    ll k = 0, T = 0, current_cost;
    /* Обозначим минимальное и максимальное количество товаров, которые может купить Сахир:
    Если у Сахира бюджет меньше чем какой-либо товар, то он купит 0 вещей (left = 0)
    Или у него может быть достаточно денег, чтобы скупить весь рынок (right = n+1) */
    ll left = 0, right = n + 1, mid;

    // Запускаем бинарный поиск
    while (left + 1 < right) {
        mid = (left + right) / 2;
        // Считаем минимальную стоимость от выбранного количества товаров
        current_cost = countCost(mid, costs, n);

        // Если уложились в бюджет
        if (current_cost <= S) {
            // То мы нашли большее k товаров, чем предыдущее (также меняем стоимость)
            k = mid;
            T = current_cost;
            // Можем попробовать взять значение побольше
            left = mid;
        }
        else {
            // Иначе пробуем взять меньшее количество товаров
            right = mid;
        }
    }

    cout << k << ' ' << T;

    return 0;
}
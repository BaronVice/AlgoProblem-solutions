#include <bits/stdc++.h>
// Из <algorithm>

using namespace std;

int main(){
    vector<int> v = { 1, 3, 3, 3, 3, 5, 7, 7, 7, 10 };
    // Есть ли элемент value в коллекции
    cout << binary_search(v.begin(), v.end(), 2) << '\n';
    cout << binary_search(v.begin(), v.end(), 3) << '\n';
    cout << '\n';

    // Первый элемент >= value
    // lower_bound() вернет итератор, чтобы получить индекс - вычтем итератор начала
    cout << lower_bound(v.begin(), v.end(), 3) - v.begin() << '\n';

    // Первый элемент > value
    // upper_bound() вернет итератор, чтобы получить индекс - вычтем итератор начала
    cout << upper_bound(v.begin(), v.end(), 3) - v.begin() << '\n';
}

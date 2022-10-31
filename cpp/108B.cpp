// Идея задачи: если число умещаетя в n-бит памяти, то его квадрат поместится 2n-бит памяти

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;

    // Размеры некоторых типов данных могут совпадать, но нам нужны уникальные значения - используем set
    set <int> types;
    int el;
    for (int i = 0; i < n; i++){
        cin >> el;
        types.insert(el);
    }
    // К set'y нельзя обращаться по индексам, поэтому перемещаем значения из set'a в вектор
    vector <int> uniqueTypes(types.size());
    int i = 0;
    for(auto &el : types){
        uniqueTypes[i] = el;
        i++;
    }
    
    // Сортируем, чтобы рассматривать последовательные пары
    sort(uniqueTypes.begin(), uniqueTypes.end());    

    bool weird = false;
    for(int i = 0; i < uniqueTypes.size() - 1; i++){
        // Если текущий тип больше следующего по величине, деленого на два, то не поместится
        if (uniqueTypes[i] > uniqueTypes[i+1] / 2){
            weird = true;
            break;
        }
    }

    cout << (weird ? "YES" : "NO");

    return 0;
}
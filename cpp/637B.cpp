// Идея задачи: используем словарь (хранит уникальные ключи с их значениями)

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;
    // Ключ - имя, значение - i
    map<string, int> chat;

    /* Будем ориентироватся на i, как на порядок в чате: чем больше у ключа значение i,
    тем выше оно будет стоять. */ 
    for (int i = 0; i < n; i++){
        string name;
        cin >> name;
        /* Если имя еще не записано, то оно будет добавлено в словарь как в начало чата,
        Иначе перезапишем значение имени на более высокое, тем самым подняв его в начало чата */
        chat[name] = i;
    }
    
    // Для упрощения сортировки преобразуем в вектор с парами, где поменяем ключи и значения местами
    vector <pair<int, string>> result;
    for(auto &i : chat){
        result.push_back(pair<int, string>(i.second, i.first));
    }
    
    // Сортируем ключи по убыванию, т.е. от большего i к меньшему i
    sort(result.rbegin(), result.rend());

    // Вывод имен
    for(auto &el : result){
        cout << el.second << endl;
    }

    return 0;
}
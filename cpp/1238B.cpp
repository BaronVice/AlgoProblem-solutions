/* Идея задачи: сортируем координаты монстров и всегда стреляем по правому (тем самым
откидывая левую часть монстров взрывной волной) до тех пор, пока мы не убьем всех взрывами
и/или ловушками, что находятся от нуля и левее */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int q, n, r;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> n >> r;

        /* На одной точке может стоять сразу несколько монстров,
        поэтому работаем только с уникальными координатами */
        set <int> coordinates;
        int el;
        for (int j = 0; j < n; j++){
            cin >> el;
            coordinates.insert(el);
        }
        /* К set'y нельзя обращаться по индексам, поэтому перемещаем значения из set'a в вектор */
        vector <int> uniqueCoordinates(coordinates.size());
        int j = 0;
        for(auto &el : coordinates){
            uniqueCoordinates[j] = el;
            j++;
        }
        // Сортируем координаты
        sort(uniqueCoordinates.begin(), uniqueCoordinates.end());

        // Общий отброс моснтров влево после выстрелов по правому
        ll explosion_distance = 0;
        // Количество выстрелов, которое потребуется для убийства всех
        int shots = 0;
        // Указатель на то, по какому монстру стреляем (изначально крайняя правая позиция)
        int pointer = coordinates.size() - 1;

        /* Пока крайнего правого не откинули взрывной волной к ловушкам
        или не убили всех выстрелами */
        while(explosion_distance < uniqueCoordinates[pointer] && pointer >= 0){
            // Выстрел
            shots++;
            // Убили крайнего правого монстра, целимся в того, кто стоит левее убитого
            pointer--;
            // Общая волна взрыва увеличилась
            explosion_distance += r;
        }

        cout << shots << endl;

    }

    return 0;
}
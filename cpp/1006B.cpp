/* Идея задачи: сумма первых k наибольших элементов и есть максимально возможная полезность.
Количество задач на каждый день будем вычислять так: идем от левого указателя (изначально
по индексу -1) до тех пор, пока не дойдем до какого-нибудь элемента в максимумах. После того,
как дошли до такого элемента, считаем длину отрезка от левого указателя до текущего индекса,
вычеркиваем найденный элемент из максимумов, перемещаем левый указатель на текущий индекс.
Повторяем процесс, пока в максимумах есть элементы. Как только они закончаться, прибавляем
к последнему дню оставшиеся справа задачи  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    // Вектор под упорядоченные задачи
    vector<int> problems(n);
    // Вектор под дальнейшую сортировку для нахождения максимумов
    vector<int> copyToSort(n);

    int el;
    for (int i = 0; i < n; i++){
        cin >> el;
        problems[i] = el;
        copyToSort[i] = el;
    }

    // Максимумы - первые k наибольших элементов
    sort(copyToSort.rbegin(), copyToSort.rend());
    vector <int> maximums(copyToSort.begin(), copyToSort.begin() + k);

    // Сумма максимумов - это и есть наибольшая общая полезность
    int maximumsSum = 0;
    for (auto &i : maximums){
        maximumsSum += i;
    }
    cout << maximumsSum << endl;

    // Левый и правый указатели - начало и конец рассматриваемого отрезка
    int left_pointer = -1, right_pointer = 0;
    // Пока еще есть максимумы
    while (maximums.size() != 0){
        // Определяем, лежит ли текущий элемент в максимумах
        auto index = find(maximums.begin(), maximums.end(), problems[right_pointer]);
        // Если лежит, то
        if (index != maximums.end()){
            // Удаляем его из максимумов
            maximums.erase(index);
            // Если это был последний максимум
            if (maximums.size() == 0){
                // То это последний день, вычисляем его
                cout << right_pointer - left_pointer + n - 1 - right_pointer;
                // n - 1 - right_pointer: прибавляем оставшиеся справа задачи
            }
            else{
                // Иначе дни еще есть, вычисляем длину текущего отрезка
                cout << right_pointer - left_pointer << ' ';
                // Смещаем начало отрезка на конец и ищем дальше отрезки
                left_pointer = right_pointer;
            }
        }
        // Рассматриваем следдующиий элемент
        right_pointer += 1;
    }

    return 0;
}
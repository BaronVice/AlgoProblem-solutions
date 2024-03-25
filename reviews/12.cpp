#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;

    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Верно: не гарантируется, что элементы упорядочены, поэтому сортируем
    sort(arr.begin(), arr.end());

    cin>>k;

    /*
    Если ты хочешь сделать что-то k раз и тебе это k не нужно, то можно сделать проще и быстрее (while k не ноль):
    while(k--){
        // что-то делаю
    }
    */

    for(int i=0; i<k; i++){
        // Для каждого набора per vtor, которых будет k штук делаем нужно посчитать ответ (answer)
        int per, vtor,answer/*, answers - это не нужно*/;
        cin>>per>>vtor;
        answer=upper_bound(arr.begin(), arr.end(), vtor)-lower_bound(arr.begin(), arr.end(), per)<<'\n';
        // И напечатаем его через пробел
        cout << answer << ' ';
        // for (auto answer : answers){
        //         cout << answer << ' ';
// } лишняя скобка
    }

    return 0;
}

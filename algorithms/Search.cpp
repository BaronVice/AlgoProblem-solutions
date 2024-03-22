#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,b,d;

    cin>>n>>k;

    vector<int> arr;
    vector<int> ak;

    // Окей...
    for(int i=0; i<n; i++){
        cin>>b;
        arr.push_back(b);
    }
    cin.clear();
    cin.ignore(1000, '\n');
    /*
    // ...но можно было сделать ввод так:
    vector<int> arr(n); // объявляем вектор и задаем ему размерность в n элементов (теперь это вектор из n нулей)
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // сразу закидываем элемент в вектор
    }
    */
    
    // Так можно, но...
    for(int j=0; j<k; j++){
        cin>>d;
        ak.push_back(d);}
    // Запросы можно принимать в переменную и сразу давать ответ
    /*
    for (int i = 0; i < k; i++){
        int toFind; cin >> toFind;
        if (binary_search(arr.begin(), arr.end(), toFind)){
            // Если нашлось
            cout << "YES\n";
        } else {
            // Если не нашлось
            cout << "NO\n";
        }
    }
    */
    
    // lower_bound/upper_bound лучше использовать, если хочешь найти позицию элемента
    // Если надо сказать есть элемент в массиве или нет - binary_search()
    for(int j=0; j<k; j++){
        // TODO: перепиши через binary_search()
        if ((lower_bound(arr.begin(), arr.end(), ak[j])-arr.begin())!=0){
            cout<<"YES"<<'\n';
        }else{cout<<"NO"<<'\n';
         }
    }

    return 0;
}

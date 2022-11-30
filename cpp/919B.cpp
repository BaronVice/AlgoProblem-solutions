#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


ll digitSum(ll number){
    ll result = 0;

    while (number != 0){
        result += number % 10;
        number /= 10;
    }

    return result;
}


int main(){

    ll k;
    cin >> k;

    ll number = 0;
    while(k != 0){
        number++;
        if (digitSum(number) == 10){
            k--;
        }
    }

    cout << number;

    return 0;
}
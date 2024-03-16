#include <bits/stdc++.h>

using namespace std;

int main(){
    long long q,w,e,r,t,y,i,o,p,l,mid,x, width, length;
    cin>>q;
    l=1;
    r=q;
    cout<<"? 1 1 "<<q<<" "<<q<<endl;
    cin>>p; 
    l=1;
    // q+1 потому что ломается на 1 1 1 1
    r=q+1;
    mid=1;
    // Дальше все правильно
    while (r-l!=1){
        mid=(r+l)/2;
        cout<<"?"<<" "<<mid<<" "<<1<<" "<<q<<" "<<q<<endl;
        cin>>o;
        if (o==p){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    x=l;
    l=1;
    r=q+1;
    mid=1;
    while (r-l!=1){
        mid=(r+l)/2;
        cout<<"?"<<" "<<1<<" "<<mid<<" "<<q<<" "<<q<<endl;
        cin>>o;
        if (o==p){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    y=l;
    // Нашли нижний левый угол, получаем верхний правый
    cout<<"?"<<" "<<x<<" "<<1<<" "<<x<<" "<<q<<endl;
    cin>>length;
    width = p / length;
    
    cout << "! " << x << " " << y << " " << x + width-1 << " " << y + length-1 <<endl;
    return 0;
}

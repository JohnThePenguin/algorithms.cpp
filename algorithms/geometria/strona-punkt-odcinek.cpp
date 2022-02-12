//geeksforgeeks.org/direction-point-line-segment/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//dziwne cos do wczytywania <= c++17
template<typename... T>
void read(T&... args){
    ((cin >> args), ...);
}

//struct jes szybszy i wygodniejszy
struct P{
    int x;
    int y;
};

ll product(P& a, P& b, P& p){
    return  ((b.x - a.x) * (p.y - a.y)) - 
            ((b.y - a.y) * (p.x - a.x));
}

// lewo wspolliniowe prawo
//  -1       0         1
// 
// punkt ma po tej stronie wektor

int side(P& a, P& b, P& p){
    ll res = product(a,b,p);

    if(res > 0)
        return 1;

    if(res < 0)
        return -1;

    if(res == 0)
        return 0;

    return 0; //zeby kompilator byl zadowolony
}

int main(){
    P a, b, c;
    while(1){//poczatek, koniec odcinka, punkt
        read(a.x, a.y, b.x, b.y, c.x, c.y);
        cout << side(a, b, c) << " ";
    }
}
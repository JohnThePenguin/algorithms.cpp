#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MIN = -1e6+7;

struct P{
    ll x;
    ll y;
    int p;//cwiartka
};

vector<P>points;

ll product(P a, P& b, P& p){
    return  ((b.x - a.x) * (p.y - a.y)) - 
            ((b.y - a.y) * (p.x - a.x));
}

// 4 | 1 
// - * -  <- cwiartki
// 3 | 2
int checkpart(P& S, P& a){ //wyznacza cwiartke ukladu z srodkiem S
    if(a.x - S.x >= 0 and a.y - S.y >= 0) return 1;
    if(a.x - S.x >= 0 and a.y - S.y <= 0) return 2;
    if(a.x - S.x <= 0 and a.y - S.y <= 0) return 3;
    if(a.x - S.x <= 0 and a.y - S.y >= 0) return 4;
    return 1;
}

//sortowanie od gornej czesci osi y, z ruchem wskazowek zegara
P Center = {0, 0};
void katsort(){

    //ustawianie cwiartki dla kazdego punkty bedzie szybciej to zrobic tu
    //size_t to long long, ale kompilator sie triggeruje 
    for(size_t i = 0; i < points.size(); i++)
        points[i].p = checkpart(Center, points[i]);
    
    sort(points.begin(), points.end(), [](P a, P b){
        if(a.p != b.p) return a.p < b.p;
        return (product(Center, a, b) < 0); //if strona b do s->a to lewa to jest ok
    });                                       //jezeli > 0 to prawa -> zamiana
}

void init(){
    int n;
    ll a, b;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        points.push_back({a,b, 0});
    }

    katsort();

    cout << "result:\n";
    for(auto e : points)
        cout << e.x << " " << e.y << "\n";
}

int main(){
    init();
}
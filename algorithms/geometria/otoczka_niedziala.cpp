#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MIN = -1e6+7;

struct P{
    ll x;
    ll y;
};

vector<P>points;
vector<P>result;

ll product(P a, P& b, P& p){
    return  ((b.x - a.x) * (p.y - a.y)) - 
            ((b.y - a.y) * (p.x - a.x));
}

void otoczka(){
    stack<P>S, RS;
    
    sort(points.begin(), points.end(), [](P a, P b){
        return a.x < b.x;
    });

    P a, b;
    S.push(points[0]);
    a = points[0];
    b = points[1];

    for(int i = 2; i < (int)points.size(); i++){

        while(product(a, b, points[i]) > 0){
            b = a; 
            S.pop();

            if(S.empty()) break;
            a = S.top();
        }

        S.push(b);
        a = b;
        b = points[i];
    }
    S.push(b);

    RS.push(points[0]);
    a = points[0];
    b = points[1];

    for(int i = 2; i < (int)points.size(); i++){

        while(product(a, b, points[i]) < 0){
            b = a; 
            RS.pop();

            if(RS.empty()) break;
            a = RS.top();
        }

        RS.push(b);
        a = b;
        b = points[i];
    }
    RS.push(b);

    cout << "\n";
    while(RS.size()){
        cout << RS.top().x << " " << RS.top().y << "\n";
        RS.pop();
    }
    cout << "\n";

    while(S.size()){
        cout << S.top().x << " " << S.top().y << "\n";
        S.pop();
    }
    //while(RS.size()){ result.push_back(RS.top()); RS.pop();}

    //reverse(result.begin(), result.end());
    //S.pop();
    //while(S.size() > 1){ result.push_back(S.top()); S.pop(); }
    
}

void init(){
    int n;
    ll a, b;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        points.push_back({a,b});
    }

    otoczka();
    cout << "\n";

    for(auto e : result)
        cout << e.x << " " << e.y << "\n";                             
}

int main(){
    init();
}

/*
12
2 1
2 5
3 7
4 2
4 6
5 9
6 5
7 1
8 3
9 8
10 6
11 2

12
4 -5
-2 -2
1 -3
4 -2
-4 -4
-6 -1
5 2
2 2
1 4
-3 2 
-4 3
1 -1
*/

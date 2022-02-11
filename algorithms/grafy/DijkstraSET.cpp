//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, int> pint;

constexpr int MAXN = 1e6+7; //liczba wierzcholkow
constexpr ll  INF = 1e18;   //najwieksza odleglosc miedzy para

vector<pint>S[MAXN];        //{odleglosc, wierzcholek}
ll dist[MAXN];

void Dijkstra(int v){
    fill(dist, dist+MAXN, INF);
    dist[v] = 0;

    pint a;
    set<pint>ST;
    ST.insert({dist[v], v});

    while(ST.size()){
        a = *ST.begin();
        ST.erase(a);

        for(auto e : S[a.sc]){
            if(dist[e.sc] > a.fs + e.fs){
                ST.erase({dist[e.sc], e.sc});
                dist[e.sc] = a.fs + e.fs;
                ST.insert({dist[e.sc], e.sc});
            }
        }
    }    
}

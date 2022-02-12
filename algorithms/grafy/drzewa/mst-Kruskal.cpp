//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6+7; //liczba elementow

int rep[MAXN];      //reprezentant grupy
int capacity[MAXN]; //zmniejsza zlozolnosc

struct edge{
    int a; //krawedz a - b o wadze w
    int b;
    int w;
};

vector<edge>graph; //wszystkie mozliwe krawedzie
vector<edge>gotowy; //krawedzie ktore trzeba wybrac dla mst

void init(int& n){  //ustawienie reprezentantow i pojemnosci dla wierzcholkow 1..n
    fill(capacity, capacity+n+1, 1); //wypelnia capacity 1
    for(int i = 0; i <= n; i++)
        rep[i]=i;
}

int uFind(int v){
    if(v != rep[v]) rep[v] = uFind(rep[v]);
    return rep[v];
}

void uUnion(int a, int b){
    a = uFind(a);
    b = uFind(b);

    if(a == b) return; //if juz sa polaczone (ten sam reprezentant)

    if(capacity[a] < capacity[b]){
        capacity[b] += capacity[a];
        rep[a] = b;
    }
    else{
        capacity[a] += capacity[b];
        rep[b] = a;
    }
}

void mst(){
    long long laczny_koszt = 0;
    // sortowanie krawedzi po wagach, tylko funkcja porownujaca jest tutaj
    sort(graph.begin(), graph.end(), [](edge a, edge b){
        return a.w < b.w;
    });

    for(auto e : graph){
        if(uFind(e.a) != uFind(e.b)){
            laczny_koszt += e.w;
            gotowy.push_back(e);

            uUnion(e.a, e.b);
        }
    }
}

int main(){
    int n, m;
    int a, b, w;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        graph.push_back({a,b,w});
    }
    init(n);
    mst();
    for(auto e : gotowy) cout << e.a << " " << e.b << " " << e.w << "\n";
}
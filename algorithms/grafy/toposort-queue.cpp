//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6+7;//liczba wierzcholkow

vector<int>S[MAXN];
int in[MAXN];

vector<int>sorted;

void makeToposort(int& n){ //ten sposob dziala tylko dla odpowiednich grafow
    queue<int>Q;
    int v;

    for(int i = 1; i <= n; i++) //dodanie wszystkich wiezcholkow o stopniu wejsciowym = 0
        if(!in[i]) Q.push(i);

    while(Q.size()){ //while size kolejki jest > 0
        v = Q.front();
        Q.pop();

        for(auto e : S[v]){
            in[e]--;
            if(!in[e])
                Q.push(e);
        }

        sorted.push_back(v);
    }
}

void input(int& m){ //wczytananie grafu
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        S[a].push_back(b);
        in[b]++;
    }
}
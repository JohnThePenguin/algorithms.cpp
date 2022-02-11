//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6+7;//liczba wierzcholkow

vector<int>S[MAXN];
vector<int>revS[MAXN]; //odwroceni sasiedzi
vector<int>conn[MAXN]; //polaczenia miedzy spojnymi
bool tseen[MAXN];
bool gseen[MAXN];

int groupid[MAXN];     //spojna do ktorej nalezy dany wierzcholek

vector<int>toposorted;
vector<int>groups;

//jakis toposort
void dfs(int v){
	tseen[v]=1;

	for(auto e : S[v])
		if(!tseen[e])
			dfs(e);
    
    toposorted.push_back(v);
}

void setgruop(int v, int& gid){
    gseen[v]=1;
    groupid[v]=gid;
    cout << v << " ";
    for(auto e : revS[v]){
        if(!gseen[e])
            setgruop(e, gid);
        else    
            conn[groupid[e]].push_back(gid);        
    }
}

int main(){ 
    int n, m; //liczba wierzcholkow, krawedzi
    int a, b; //pomocnicze
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        S[a].push_back(b);
        revS[b].push_back(a); //odwrucona krawedz
    }
    
    for(int i = 1; i <= n; i++) //przejscie po wszystkich wierzcholkach i zrobienie toposorta
        if(!tseen[i])
            dfs(i);

    reverse(toposorted.begin(), toposorted.end());   

    for(auto e : toposorted){   // przejscie po wierzcholkach w kolejnosci toposorta
                                // i puszczenie dfs ustalajacego spojna
        if(!gseen[e]){
            cout << e << ":  ";
            setgruop(e, e);
            cout << "\n";
            groups.push_back(e);// spojne rowniez posortowane sa topologicznie
        }
    }
}
//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6+7;//liczba wierzcholkow

vector<int>S[MAXN];
bool seen[MAXN];

vector<int>sorted;

void dfs(int v){
	seen[v]=1;

	for(auto e : S[v])
		if(!seen[e])
			dfs(v);
    
    sorted.push_back(v);
}

void init(int& n){ //puszczenie dfs z kazdego z wierzcholkow (w zadaniu to nie musi byc od 1 do n), odwrocenie gotowej tablicy
    for(int i = 1; i <= n; i++)
        if(!seen[i])
            dfs(i);

    reverse(sorted.begin(), sorted.end());   
}


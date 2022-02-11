//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6+7;//liczba wierzcholkow

vector<int>S[MAXN];
bool seen[MAXN];

void dfs(int v){
	seen[v]=1;

	for(auto e : S[v])
		if(!seen[e])
			dfs(v);
}



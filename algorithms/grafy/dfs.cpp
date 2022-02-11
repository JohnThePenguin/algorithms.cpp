
vector<int>S[MAXN];
bool seen[MAXN];

void dfs(int v){
	for(auto e : S[v])
		if(!seen[e])
			dfs(v);
}



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxx = 5e5+7, LOG = 20;

struct xyz
{
    long long x,y;
};

vector<xyz>g[maxx]; long long depth[maxx]; long long odl[maxx]; long long parent[maxx]; bool odw[maxx]; long long up[maxx][LOG];

void dfs(long long v)
{
    odw[v] = true;
    up[v][0] = parent[v];
    for(int j=1; LOG-1>j; j++)
    {
        up[v][j] = up[up[v][j-1]][j-1];
    }
    for(int i=0; g[v].size()>i; i++)
    {
        if(!odw[g[v][i].x])
        {
            //odl[g[v][i].x] = g[v][i].y + odl[v];
            depth[g[v][i].x] = depth[v] + 1;
            parent[g[v][i].x] = v;
            dfs(g[v][i].x);
        }
    }
}

long long getlca(long long a, long long b)
{
    if(depth[a] < depth[b]) swap(a,b);

    long long k = depth[a] - depth[b];

    for(int i=LOG-1; i >= 0; i--)
    {
        if( k & (1 << i))
        {
            a = up[a][i];
        }
    }

    if(a==b) return b;

    for(int i=LOG-1; i>=0; i--)
    {
        if(up[a][i] != up[b][i])
        {
            a = up[a][i]; b = up[b][i];
        }
    }
    return up[a][0];

}

int main()
{
    int n; cin>>n; for(int i=1; n>i; i++){
        int a,b,c; cin>>a>>b>>c; // c to odlegosc wiec nie trzeba
        g[a].push_back({b,c}); g[b].push_back({a,c});
    }

    dfs(1);
}

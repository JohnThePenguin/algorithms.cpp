#include <iostream>
#include <vector>
using namespace std;
const int maxx = 1e6+7, LOG = 18;
#define pb push_back
struct xyz
{
    int x,y;
};
int depth[maxx], parent[maxx], up[maxx][LOG];
vector<xyz>g[maxx];

void pre(int n)
{
    for(int i=1; n>=i; i++)
    {
        up[i][0] = parent[i];
        for(int j=1; LOG-1>=j; j++)
        {
            up[i][j]=up[ up[i][j-1] ][j-1];
        }
    }
}

int getlca(int a, int b)
{
    if(depth[a]<depth[b]) swap(a,b);
    
    int k = depth[a] - depth[b];
    
    for(int i = LOG - 1; i >= 0; i--)
    {
        if( k & (1 << i))
        {
            a = up[a][i];
        }
    }
    
    if(a==b) return a;
    
    for(int i = LOG - 1; i>=0; i--)
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
    int n; cin>>n;
    for(int i=0; n-1>i; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        g[a].pb({b,c}); parent[b]=a; depth[b]=depth[a]+1;
    }
    
    pre(n);
    
    while(true)
    {
        cout<<endl;
        int a,b; cin>>a>>b;
        cout<<getlca(a,b)<<endl;
    }

}
/*
 5
 1 2 1
 1 3 3
 1 4 2
 4 5 3

 2 3
 1 5
 4 5
 4 3
 5 5
 -1
 
 */

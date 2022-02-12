//kod do przydzielania adresów

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e5+1;

ll k,l;
string a,b;
vector<pair<ll,ll>> hsh, vec;
ll mod1 = 1e9+9, mod2 = 1e9+7;
ll p = 997;
ll pw[maxn][2];
unordered_map<ll,bool> m1,m2;

void sethash(string& s, vector<pair<ll,ll>>& hsh)
{
    s = '#' + s;
    hsh = vector<pair<ll,ll>>(s.size(),{0,0});
    for(ll i = 1; i < s.size(); i++)
    {
        hsh[i].first  = (s[i] + hsh[i-1].first *p % mod1) % mod1;
        hsh[i].second = (s[i] + hsh[i-1].second*p % mod2) % mod2;
    }
}
pair<ll,ll> gethash(const vector<pair<ll,ll>>& hsh, ll a, ll b)
{
    if(!a) return hsh[b]; 
    auto x = (hsh[b].first  - hsh[a-1].first  * pw[b-a+1][0] % mod1 + mod1) % mod1; 
    auto y = (hsh[b].second - hsh[a-1].second * pw[b-a+1][1] % mod2 + mod2) % mod2; 
    return {x,y};
}
void havefun(ll len)
{
    for(ll i = 1; i+len-1 < hsh.size(); i++)
    {
        auto x = gethash(hsh, i, i+len-1);
        m1[x.first]  = true;
        m2[x.second] = true;
    }
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    pw[0][0] = pw[0][1] = 1;
    for(ll i = 1; i < maxn; i++)
    {
        pw[i][0] = pw[i-1][0]*p % mod1;
        pw[i][1] = pw[i-1][1]*p % mod2;
    }
    cin >> a;
    sethash(a,hsh);

    cin >> k;
    for (ll i = 0; i < k; i++)
    {
        cin >> l;
        m1.clear();
        m2.clear();

        cin >> b;
        havefun(b.size());

        for(ll i = 0; i < l; i++)
        {
            if(i) cin >> b;
            sethash(b,vec);
            auto x = vec[vec.size()-1];
            if(m1[x.first] && m2[x.second]) cout << "OK" << '\n';
            else cout << "NIE" << '\n';
        }
    }
}

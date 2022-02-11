#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int BASE = 1 << 20; //1 << <log2 MAXN>
int tree[BASE*2];
int modi[BASE*2];

ll aread(int v){
    ll w = 0;
    v += BASE;

    while(v){
        w += tree[v];
        v/=2;
    }
}

void aupdate(int l, int r, int x){

    l += BASE-1; //rozszerzenie przedzialu, aby isc po zewnetrznych i dodawac co jest w srodku
    r += BASE+1;

    while(r - l > 1){
        if(!(l&1)) tree[l+1] += x;  //if l jest nieparzyste
        if(r&1)    tree[r-1] += x;  //if r jest parzyste 

        l/=2; r/=2;
    }
}
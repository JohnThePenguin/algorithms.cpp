//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int BASE = 1 << 20; //1 << <log2 MAXN>
int tree[BASE*2];
int modi[BASE*2];

void aupdate(int v, int x){
    v += BASE;

    while(v){
        tree[v] += x;
        v/=2;
    }
}

ll aread(int l, int r){
    ll w = 0;

    l += BASE-1; //rozszerzenie przedzialu, aby isc po zewnetrznych i dodawac co jest w srodku
    r += BASE+1;

    while(r - l > 1){
        if(!(l&1)) w += tree[l+1];  //if l jest nieparzyste
        if(r&1)    w += tree[r-1];  //if r jest parzyste 

        l/=2; r/=2;
    }
    return w;
}
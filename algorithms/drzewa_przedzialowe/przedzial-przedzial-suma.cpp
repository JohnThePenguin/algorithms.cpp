//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int BASE = 1 << 20;

int tree[BASE*2];
int modi[BASE*2];

#define l (v<<1)
#define r ((l)+1)
#define m ((a+b)/2)

void bash(int& v, int& a, int& b){
    if(!modi[v]) return;

    tree[l] += modi[v]/2;
    modi[l] += modi[v]/2;

    tree[r] += modi[v]/2;
    modi[r] += modi[v]/2;

    modi[v] = 0;
}

void aupdate(int v, int a, int b, int p, int k, int& x){
    if(k < a or b < p) return;
    if(p <= a and b <= k){
        tree[v] += (b-a+1) * x;
        modi[v] += (b-a+1) * x;
    }
    else{
        bash(v, a, b);

        aupdate(l, a, m+1, p, k, x);
        aupdate(r, m+1, b, p, k, x);

       tree[v] = tree[l] + tree[r];
    }
}

ll aread(int v, int a, int b, int p, int k){
    if(k < a or b < p) return 0;
    if(p <= a and b <= k){
        return tree[v];
    }
    else{
        bash(v, a, b);

        return aread(l, a, m, p, k) + aread(r, m+1, b, p, k);
    }
}
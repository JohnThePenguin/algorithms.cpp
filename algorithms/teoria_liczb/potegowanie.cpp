//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9+7;

ll fastpow(ll a, ll n){
    ll w = 1;
    while(n){
        if(n%2) w = (w * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return w;
}

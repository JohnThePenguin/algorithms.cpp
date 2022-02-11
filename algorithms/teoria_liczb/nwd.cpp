//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nwd(ll a, ll b){
    while(b) swap(a %= b, b);
    return a;
}
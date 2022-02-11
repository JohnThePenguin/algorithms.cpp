//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6+7; //liczba elementow

int rep[MAXN];      //reprezentant grupy
int capacity[MAXN]; //zmniejsza zlozolnosc

void init(){
    fill(capacity, capacity+MAXN, 1); //wypelnia capacity 1
    for(int i = 0; i < MAXN; i++)
        rep[i]=i;
}

int uFind(int v){
    if(v != rep[v]) rep[v] = uFind(rep[v]);
    return rep[v];
}

void uUnion(int a, int b){
    a = uFind(a);
    b = uFind(b);

    if(a == b) return; //if juz sa polaczone (ten sam reprezentant)

    if(capacity[a] < capacity[b]){
        capacity[b] += capacity[a];
        rep[a] = b;
    }
    else{
        capacity[a] += capacity[b];
        rep[b] = a;
    }
}
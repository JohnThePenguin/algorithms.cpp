//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+7; //maksymalny rozimiar wyrazu
int KMP[MAX];

string s;

void kmpalgo(){

    int a;
    int n = s.size();

    s = '$' + s;       //znak ktory nie wystepuje w wyrazie
    KMP[0] =  -1;

    for(int i = 2; i <= n; i++){

        a = KMP[i-1];
        while(a != -1 && s[i] != s[a + 1])
            a = KMP[a];
        
        KMP[i] = a + 1;
    }
}
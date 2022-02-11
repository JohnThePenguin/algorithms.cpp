//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

int sorted[(int)1e6+7];

int bin(int a, int b, int x){
    int mid;
    while(a < b){
        mid = (a+b)/2;
        if(sorted[mid] < x) a = mid + 1;
        else b = mid;
    }
    return a;
}
//code from https://github.com/JohnThePenguin/algorithms.cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e6+7; //szukamy liczb pierwszych < MAX
bool prime[MAX];

void sito(){
    fill(prime+2, prime+MAX, 1);

    for(int i = 2; i*i < MAX; i++){ //iteracja do i*i < MAX, bo jezeli i*i > MAX, 
                                    //to i tak juz sie nie zaznaczy w tablicy [MAX]
        if(!prime[i]) continue;

        for(int j = i*i; j < MAX; j += i)
            prime[j] = 0;
    }

    for(int i = 0; i < 1000; i++)
        if(prime[i])
            cout << i << "\n";
}
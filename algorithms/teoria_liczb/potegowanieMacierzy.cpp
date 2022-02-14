//na podstawie zadania "Liczby Fibonacciego też dla starszych"
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3; //rozmiar macierzy
const long long MOD = 123456789; //modulo
long long result[MAXN][MAXN]; //macierz z wynikami
long long p[MAXN][MAXN]; //macierz na poczatku
long long helper[MAXN][MAXN]; //macierz pomocnicza (do wyliczania mnozenia)

//w tej implementacji macierze indeksujemy od 1

//mnozenie macierzy tab * macierz tab2
void multiply(long long (&tab)[MAXN][MAXN], long long (&tab2)[MAXN][MAXN], long long (&helper)[MAXN][MAXN]){
    //zerowanie macierzy pomocniczej
    for(int i = 1; i < MAXN; i++){
        for(int j =1; j < MAXN; j++){
            helper[i][j] = 0;
        }
    }
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            for(int k = 1; k < MAXN; k++){
                helper[i][j] += tab[i][k] * tab2[k][j];
                if(helper[i][j] >= MOD){
                    helper[i][j] %= MOD;
                }
            }
        }
    }
    //przepisywanie macierzy pomocniczej do macierzy wynikowej
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            tab[i][j] = helper[i][j];
        }
    }
}


void power(int n){
    //neutralna macierz (macierz jednostkowa)
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            result[i][j] = (i==j);
        }
    }
    while(n){
        if(n%2 == 1){
            multiply(result, p, helper);
        }
        multiply(p, p, helper);
        n/=2;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    //macierz poczatkowa (f(i) - i-ta liczba fibbonaciego)
    //[1 1] = [f(2), f(1)]
    //[1 0] = [f(1), f(0)]
    p[1][1] = 1;
    p[1][2] = 1;
    p[2][1] = 1; 
    power(n);
    cout << result[1][2];
    //result wyglada tak:
    //[f(n+1), f(n)]
    //[f(n), f(n-1)]
}

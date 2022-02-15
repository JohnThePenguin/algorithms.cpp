#include <iostream>
using namespace std;

unsigned long long a, b, m;

unsigned long long modular_multiply(unsigned long long a,unsigned long long b)
{
    unsigned long long wynik = 0;

    a %= m;
    while(b > 0)
    {
        if(b % 2 == 1)
        {
            wynik = (wynik + a) % m;
        }
        a = (a * 2) % m;
        b /= 2;
    }

    return wynik % m;

}
unsigned long long potega(unsigned long long a, unsigned long long b, unsigned long long m)
{
    unsigned long long c = 1;
    while(b > 0)
    {
        if( b % 2 == 1)
        {
            c %= m;
            a %= m;
            c = modular_multiply(c,a) % m;
        }
        a = modular_multiply(a,a) % m;
        b /= 2;

    }
    return c % m;
}


int main()
{
    cin >> a >> b >> m;

    cout << potega(a, b, m);

}

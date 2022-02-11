// ten plik zawiera driver do zadania 'przydzielanie adresów'
// obsługuje hashowanie z modulo na 3 liczby pierwsze

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>

// macros

#define MOD1 1'000'000'007
#define MOD2 1'000'000'009
#define MOD3 1'000'000'021

#define BASE 100'000

// tables

using namespace std;

long long h1[BASE + 1];
long long h2[BASE + 1];
long long h3[BASE + 1];


long long pot1[BASE + 1];
long long pot2[BASE + 1];
long long pot3[BASE + 1];

char s[BASE + 1];

// global variables

const long long p = 1'007;

string query;

long long main_hash1;
long long main_hash2;
long long main_hash3;

// functions

long long podsl1(int i, int j)
{
	return (h1[j] + MOD1 - ((((h1[i - 1] * pot1[j - i + 1]) % MOD1) + MOD1) % MOD1)) % MOD1;
}

long long podsl2(int i, int j)
{
	return (h2[j] + MOD2 - ((((h2[i - 1] * pot2[j - i + 1]) % MOD2) + MOD2) % MOD2)) % MOD2;
}

long long podsl3(int i, int j)
{
	return (h3[j] + MOD3 - ((((h3[i - 1] * pot3[j - i + 1]) % MOD3) + MOD3) % MOD3)) % MOD3;
}

// hash na przedziale


inline long long _podsl1(int i, int j, int k, int l, int s)
{
	long long a = (h1[j][s] + MOD1 - (h1[i - 1][s] * pot1[j - i + 1]) % MOD1) % MOD1;
	a *= pot1[l - k + 1];
	a %= MOD1;
	long long b = (h1[l][s] + MOD1 - (h1[k - 1][s] * pot1[l - k + 1]) % MOD1) % MOD1;
	return (a + b) % MOD1;
}

inline long long _podsl2(int i, int j, int k, int l, int s)
{
	long long a = (h2[j][s] + MOD2 - (h2[i - 1][s] * pot2[j - i + 1]) % MOD2) % MOD2;
	a *= pot2[l - k + 1];
	a %= MOD2;
	long long b = (h2[l][s] + MOD2 - (h2[k - 1][s] * pot2[l - k + 1]) % MOD2) % MOD2;
	return (a + b) % MOD2;
}

// setup

void setup()
{
	
	pot1[0] = 1;
	pot2[0] = 1;
	pot3[0] = 1;
	
	for(int i = 1; i <= BASE; ++i)
	{
		pot1[i] = (pot1[i - 1] * p) % MOD1;
	}
	
	for(int i = 1; i <= BASE; ++i)
	{
		pot2[i] = (pot2[i - 1] * p) % MOD2;
	}
	
	for(int i = 1; i <= BASE; ++i)
	{
		pot3[i] = (pot3[i - 1] * p) % MOD3;
	}
	
	h1[0] = 0;
	h2[0] = 0;
	h3[0] = 0;
	
	for(int i = 1; i <= BASE; ++i)
	{
		h1[i] = (h1[i - 1] * p + s[i]) % MOD1;
	}
	
	for(int i = 1; i <= BASE; ++i)
	{
		h2[i] = (h2[i - 1] * p + s[i]) % MOD2;
	}
	
	for(int i = 1; i <= BASE; ++i)
	{
		h3[i] = (h3[i - 1] * p + s[i]) % MOD3;
	}
}

void compute_hash1()
{
	main_hash1 = 0;
	for(size_t i = 1; i <= query.size(); ++i)
	{
		main_hash1 *= p;
		main_hash1 += query[i - 1];
		main_hash1 %= MOD1;
	}
}

void compute_hash2()
{
	main_hash2 = 0;
	for(size_t i = 1; i <= query.size(); ++i)
	{
		main_hash2 *= p;
		main_hash2 += query[i - 1];
		main_hash2 %= MOD2;
	}
}

void compute_hash3()
{
	main_hash3 = 0;
	for(size_t i = 1; i <= query.size(); ++i)
	{
		main_hash3 *= p;
		main_hash3 += query[i - 1];
		main_hash3 %= MOD3;
	}
}

// |\/| /\ | /\/

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string str;
	cin >> str;
	
	for(size_t i = 1; i <= str.size(); ++i)
	{
		s[i] = str[i - 1];
	}
	
	setup();
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
	{
		int m;
		cin >> m;
		
		unordered_set<long long> guesses1;
		vector<long long> order1;
		
		unordered_set<long long> guesses2;
		vector<long long> order2;
		
		unordered_set<long long> guesses3;
		vector<long long> order3;
		
		for(int a = 1; a <= m; ++a)
		{
			cin >> query;
			compute_hash1();
			guesses1.insert(main_hash1);
			order1.push_back(main_hash1);
		
			compute_hash2();
			guesses2.insert(main_hash2);
			order2.push_back(main_hash2);
	
			compute_hash3();
			guesses3.insert(main_hash3);
			order3.push_back(main_hash3);
		}
		
		for(size_t i = 1; i <= str.size()-query.size()+1; ++i)
		{
			if(guesses1.find(podsl1(i, i + query.size() - 1)	) != guesses1.end())
			{
				guesses1.erase(podsl1(i, i+query.size()-1));
			}
			
			if(guesses2.find(podsl2(i, i + query.size() - 1)	) != guesses2.end())
			{
				guesses2.erase(podsl2(i, i+query.size()-1));
			}
			
			if(guesses3.find(podsl3(i, i + query.size() - 1)	) != guesses3.end())
			{
				guesses3.erase(podsl3(i, i+query.size()-1));
			}
		}
		
		for(size_t i = 0; i < order1.size(); ++i)
		{
			if(guesses1.find(order1[i]) == guesses1.end() && guesses2.find(order2[i]) == guesses2.end() && guesses3.find(order3[i]) == guesses3.end())
			{
				cout << "OK\n";
			}
			else
			{
				cout << "NIE\n";
			}
		}
	}
	
	

	
	return 0;
}

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

#define __BASE 2000000

using namespace std;

int pref[__BASE + 10];
int suf[__BASE + 10];

int main()
{
	string t, s, str, str2;
	cin >> t >> s;
	
	str = s + '#' + t;
	
	reverse(t.begin(), t.end());
	reverse(s.begin(), s.end());
	str2 = s + '#' + t;
	
	int current_roof_begin = 1, current_roof_end = 0, d;
	
	//pref[1] = str.size() - 1;
	
	for(int i = 2; i < str.size(); ++i)
	{
		if(i > current_roof_end || i + pref[i - current_roof_begin] == current_roof_end)
		{
			d = max(i, current_roof_end);
			
			while(str[d] == str[d - i] && d < str.size())
			{
				++d;
			}
			
			pref[i] = d - i;
			current_roof_begin = i;
			current_roof_end = d - 1;
		}
		else if(i + pref[i - current_roof_begin] > current_roof_end)
		{
			pref[i] = current_roof_end - i + 1;
		}
		else if(i + pref[i - current_roof_begin] < current_roof_end)
		{
			pref[i] = i - current_roof_begin;
		}
	}
	
	current_roof_begin = 1, current_roof_end = 0;
	
	for(int i = 2; i < str2.size(); ++i)
	{
		if(i > current_roof_end || i + suf[i - current_roof_begin] == current_roof_end)
		{
			d = max(i, current_roof_end);
			
			while(str2[d] == str2[d - i] && d < str2.size())
			{
				++d;
			}
			
			suf[i] = d - i;
			current_roof_begin = i;
			current_roof_end = d - 1;
		}
		else if(i + suf[i - current_roof_begin] > current_roof_end)
		{
			suf[i] = current_roof_end - i + 1;
		}
		else if(i + suf[i - current_roof_begin] < current_roof_end)
		{
			suf[i] = i - current_roof_begin;
		}
	}
	
	/*cout << str << endl;
	
	for(int i = 0; i <= 40; ++i)
	{
		cout << pref[i];
	}
	
	cout << "\n" << str2 << endl;
	
	for(int i = 0; i <= 40; ++i)
	{
		cout << suf[i];
	}*/
	
	if(pref[s.size() + 1] == s.size() || suf[str.size() - 1] == s.size())
	{
		cout << "TAK";
		return 0;
	}
	
	for(int a = 0; a < t.size() - 1; ++a)
	{
		//cout << pref[s.size() + 1 + a] << " " << suf[str.size() - 1 - a] << endl;
		if(pref[s.size() + 2 + a] + suf[str.size() - 1 - a] == s.size())
		{
			cout << "TAK";
			return 0;
		}
	}
	
	cout << "NIE";
	
	return 0;
}

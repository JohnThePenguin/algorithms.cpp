// Przemysław Porczyński 2020

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

typedef pair<long long, long long> point;

point start;
stack<point> hull;
vector<point> tab(500'000);

long long distance_squared(point a, point b)
{
    return ((long long)a.first - b.first)*(a.first - b.first) + ((long long)a.second - b.second)*(a.second - b.second);
}

long double dist(point a, point b)
{
    return sqrt(pow((long double)b.first - a.first, 2) +
                pow((long double)b.second - a.second, 2) * 1.0);
}

long long iloczyn_wektorowy(point a, point b, point c)
{
	long long a1 = c.first - a.first, b1 = c.second - a.second;
	long long a2 = b.first - a.first, b2 = b.second - a.second;
	return a1*b2 - a2*b1;
}

void create_convex_hull()
{
	hull.push(tab[0]);
	
	point a = tab[0], b = tab[1];
	
	for(size_t i = 2; i < tab.size(); ++i)
	{
		while(iloczyn_wektorowy(a, b, tab[i]) >= 0)
		{
			b = a;
			hull.pop();
			if(hull.empty())
			{
				break;
			}
			a = hull.top();
		}
		
		hull.push(b);
		a = b;
		b = tab[i];
	}
}

bool porownaj(point a, point b)
{
	if((a.second - start.second) * (b.first - start.first) == (a.first-start.first) * (b.second - start.second))
	{
		return a.first < b.first;
	}
		
	return (a.second - start.second) * (b.first - start.first) < (a.first - start.first) * (b.second - start.second);
}



int main()
{
	long long n;
	cin >> n;
	
	tab.resize(n);
	
	cin >> tab[0].first >> tab[0].second;
	
	long long loc = 0;
	start = tab[0];
	
	for(long long i = 1; i < n; ++i)
	{
		cin >> tab[i].first >> tab[i].second;
		
		if(tab[i].second < start.second)
		{
			start = tab[i];
			loc = i;
		}
		else if(tab[i].second == start.second && tab[i].first < start.first)
		{
			start = tab[i];
			loc = i;
		}
	}
	
	swap(tab[0], tab[loc]);
	
	cout << setprecision(10) << fixed;
	
	if(n == 1)
	{
		cout << 0.f;
		return 0;
	}
	else if(n == 2)
	{
		cout << sqrt((long double)(distance_squared(tab[0], tab[1])));
		return 0;
	}
	else if(n == 3)
	{
		cout << sqrt((long double)(distance_squared(tab[0], tab[1]))) + sqrt((long double)(distance_squared(tab[1], tab[2]))) + sqrt((long double)(distance_squared(tab[2], tab[0])));
		return 0;
	}
	
	sort(tab.begin() + 1, tab.end(), porownaj);
	tab.push_back(start);

	create_convex_hull();
	
	point first = hull.top();
	
	long double distance = 0;
	point last = first;
	hull.pop();
	
	while(!hull.empty())
	{
		distance += dist(last, hull.top());
		last = hull.top();
		hull.pop();
	}
	
	distance += dist(last, first);
	cout << distance;

	return 0;
}

/**
 * @file temp.cpp
 * @date 2022-02-07
 * Link : https://codeforces.com/contest/1634/problem/C
 * 
 * Idea : Even and Odd number should not come adjacent, other things will be taken care
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin >> t;
 
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int evens = 0, odds = 0;
		if(n*k % 2 == 0)
		{
			evens = (n*k)/2;
			odds = evens;
		}
		else
		{
			evens = (n*k)/2;
			odds = evens+1;
		}
 
		if(evens % k == 0 && odds % k == 0)
		{
			cout << "YES\n";
			int x = 1;
			while(odds)
			{
				for(int i = 0; i < k; ++i)
				{
					cout << x << " ";
					x += 2;
					odds--;
				}
				cout << '\n';
			}
 
			x = 2;
			while(evens)
			{
				for(int i = 0; i < k; ++i)
				{
					cout << x << " ";
					x += 2;
					evens--;
				}
				cout << '\n';
			}
		}
		else
		{
			cout << "NO\n";
		}
	}
}

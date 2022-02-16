/**
 * @author Vishwam Shriram Mundada
 * https://codeforces.com/contest/1637/problem/C
 * Easy
 */
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		vector<ll> a(n);
		ll sum = 0, e = 0, o = 0, s = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
			if(i > 0 && i < n-1)
			{
				sum += a[i];
				if(a[i] % 2 == 0)
					e++;
				else
					o++;
				
				if(a[i] > 1)
					s++;
			}
		}
		
		if((s == 0) || (e == 0 && o == 1))
			cout << "-1\n";
		else
			cout << (sum + o)/2 << '\n';
	}
}

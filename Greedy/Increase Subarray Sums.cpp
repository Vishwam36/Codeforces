/**
 * @author Vishwam Shriram Mundada
 * @link : https://codeforces.com/contest/1644/problem/C
 * @ref : https://codeforces.com/blog/entry/100227
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
		int n, x;
		cin >> n >> x;

		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		vector<int> maxsum(n+1, INT_MIN);
		for(int len = 1; len <= n; ++len)
		{
			int l = 0, sum = 0;
			for(int r = 0; r < len; ++r)
				sum += a[r];
			maxsum[len] = max(maxsum[len], sum);

			for(int r = len; r < n; ++r)
			{
				sum -= a[l++];
				sum += a[r];
				maxsum[len] = max(maxsum[len], sum);
			}
		}

		for(int k = 0; k <= n; ++k)
		{
			int sum = 0;
			for(int len = 1; len <= n; ++len)
				sum = max(sum, maxsum[len] + min(len,k)*x);
			
			cout << sum << ' ';
		}
		cout << '\n';
	}
}

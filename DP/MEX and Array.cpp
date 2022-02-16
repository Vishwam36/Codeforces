// https://codeforces.com/contest/1637/problem/B
// Decent

/**
 * @author Vishwam Shriram Mundada
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll find_mex(vector<ll> &a, int l, int r)
{
	set<ll> s;
	for(int i = l; i <= r; ++i)
		s.insert(a[i]);
 
	ll i = 0;
	for(auto it : s)
	{
		if(it != i)
			return i;
		++i;
	}
	return i;
}
     
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		vector<vector<ll> > mex(n, vector<ll>(n));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				mex[i][j] = find_mex(a, i, j);
 
		vector<vector<ll> >dp(n+1, vector<ll>(n+1, 0));
		
		for(int i = 0; i < n; ++i)
			for(int j = i; j < n; ++j)
			{
				dp[i][j] = 1 + mex[i][j];
				for(int k = i; k < j; ++k)
					dp[i][j] = max(dp[i][j], dp[i][k] + mex[k+1][j] + 1);
			}
 
		ll ans = 0;
		for(ll i = 0; i < n; ++i)
			for(int j = i; j < n; ++j)
				ans = ans + dp[i][j];
		
		cout << ans << '\n';
	}
}

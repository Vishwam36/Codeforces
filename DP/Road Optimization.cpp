// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1625/problem/C
// Decent

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<vector<int> > dp;

int rec(int idx, vector<int> &d, vector<int> &a, int k)
{
	if(idx >= n)
		return 0;
	if(dp[idx][k] != -1)
		return dp[idx][k];
	if(k == 0)
		return dp[idx][k] = ((d[idx+1]-d[idx])*a[idx]) + rec(idx+1, d, a, k);
	
	int ans = INT_MAX;
	for(int i = 0; i <= k; ++i)
		if(idx+i+1 <= n)
			ans = min(ans, ((d[idx+i+1]-d[idx])*a[idx]) + rec(idx+i+1, d, a, k-i));
    
	return dp[idx][k] = ans;
}

int main()
{
	int l, k;
	cin >> n >> l >> k;
	
	vector<int> d(n), a(n);

	for(int i = 0; i < n; ++i)
		cin >> d[i];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	d.push_back(l);
	dp = vector<vector<int> >(n+1, vector<int>(k+1, -1));
	cout << rec(0, d, a, k) << '\n';
}

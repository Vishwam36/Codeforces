/**
 * @author Vishwam Shriram Mundada
 * @link https://codeforces.com/contest/1637/problem/D
 * @ref https://www.youtube.com/watch?v=7iYND5KjsqI
 * @brief Good question
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i)
			cin >> b[i];
		
		int sq_sums = 0, total_sum = 0;
		for(int i = 0; i < n; ++i)
		{
			sq_sums += a[i]*a[i] + b[i]*b[i];
			total_sum += a[i] + b[i];
		}
		sq_sums = (n-2)*sq_sums;

		vector<vector<bool> > dp(n+1, vector<bool>(10001, false));
		dp[0][0] = true;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= 10000; ++j)
				dp[i][j] = (j-a[i-1] >= 0 ? dp[i-1][j-a[i-1]] : false) || (j-b[i-1] >= 0 ? dp[i-1][j-b[i-1]] : false);
		
		int ans = INT_MAX;
		for(int j = 0; j <= 10000; ++j)
			if(dp[n][j] == true)
				ans = min(ans, sq_sums + j*j + (total_sum-j)*(total_sum-j));
		
		cout << ans << '\n';
	}
}

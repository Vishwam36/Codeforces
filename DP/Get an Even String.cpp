/**
 * @author Vishwam Shriram Mundada
 * @link https://codeforces.com/contest/1660/problem/C @endlink
 * @brief Good question 3D DP
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int rec(int idx, bool f, char pre, string &s, vector<vector<vector<int> > > &dp)
{
	if(idx == s.size())
		return f == 1;
	
	if(dp[idx][pre-'a'][f] != -1)
		return dp[idx][pre-'a'][f];
	
	char c = s[idx];
	int ans = rec(idx+1, f, pre, s, dp) + 1;
	
	if(f == 1)
	{
		if(pre == s[idx])
			ans = min(ans, rec(idx+1, 0, s[idx], s, dp));
		else
			ans = min(ans, rec(idx+1, 1, s[idx], s, dp) + 1);
	}
	else
	{
		ans = min(ans, rec(idx+1, 1, s[idx], s, dp));
	}

	return dp[idx][pre-'a'][f] = ans;
}

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
		string s;
		cin >> s;
		vector<vector<vector<int> > > dp(s.size()+1, vector<vector<int> >(27, vector<int>(2, -1)));
		cout << rec(0, 0, 'z'+1, s, dp) << endl;
	}
}

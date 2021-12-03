// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1613/problem/D
// Good question, DP

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t = 0;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;

		vector<ll> dp1(n+2, 0), dp2(n+2, 0);
		// dp1[x] = # sequences with MEX = x and sequence type 0...,1...,2...,x-1...
		// dp2[x] = # sequences with MEX = x and sequence type 0...,1...,2...,x-1...,x+1...,x-1...,x+1...
		// These are only two possible sequence types
		dp1[0] = 1; // empty sequence has MEX = 0

		while(n--)
		{
			ll x;
			cin >> x;

			dp1[x+1] += dp1[x+1];
			dp1[x+1] %= mod;
			dp1[x+1] += dp1[x];
			dp1[x+1] %= mod;

			if(x > 0)
			{
				dp2[x-1] += dp2[x-1];
				dp2[x-1] %= mod;
				dp2[x-1] += dp1[x-1];
				dp2[x-1] %= mod;
			}

			dp2[x+1] += dp2[x+1];
			dp2[x+1] %= mod;
		}

		ll ans = 0;
		for(auto x : dp1)
		{
			ans += x;
			ans %= mod;
		}
		for(auto x : dp2)
		{
			ans += x;
			ans %= mod;
		}

		ans = (ans-1+mod) % mod; // remove empty sequence
		cout << ans << endl;
    }
}

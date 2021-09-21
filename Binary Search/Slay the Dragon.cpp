// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1574/problem/C
// Decent

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll sum = 0;

ll minCoins(vector<ll> &a, ll x, ll y)
{
	ll ans = LLONG_MAX;
	
	int lb = lower_bound(a.begin(), a.end(), x) - a.begin();

	if(lb < a.size())
		ans = min(ans, max((ll)0, y - (sum - a[lb])));
	
	lb--;
	if(lb >= 0)
		ans = min(ans, x - a[lb] + max((ll)0, y - (sum - a[lb])));
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll n = 0;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	
	ll m = 0, deffence, attack;
	cin >> m;
	
	for(int i = 0; i < m; ++i)
	{
		cin >> deffence >> attack;
		cout << minCoins(a, deffence, attack) << endl;
	}
}

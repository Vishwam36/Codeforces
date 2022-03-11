/**
 * @author Vishwam Shriram Mundada
 * @link https://codeforces.com/contest/1651/problem/C
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
ll mod = 1e9 + 7;

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;

		vector<ll> a(n), b(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i)
			cin >> b[i];

		ll ans = abs(a[0]-b[0]) + abs(a[n-1]-b[n-1]);
		ans = min(ans, abs(a[0]-b[n-1]) + abs(a[n-1]-b[0]));

		ll a0, a1, a2, a3;
		a0 = a1 = a2 = a3 = INT_MAX;

		for(int i = 0; i < n; ++i)
		{
			a0 = min(a0, abs(a[0]-b[i]));
			a1 = min(a1, abs(a[n-1]-b[i]));
			a2 = min(a2, abs(b[0]-a[i]));
			a3 = min(a3, abs(b[n-1]-a[i]));
		}

		ans = min(ans, abs(a[0]-b[0]) + a1+a3);
		ans = min(ans, abs(a[n-1]-b[n-1]) + a0+a2);
		ans = min(ans, abs(a[0]-b[n-1]) + a2+a1);
		ans = min(ans, abs(b[0]-a[n-1]) + a0+a3);
		ans = min(ans, a0+a1+a2+a3);

		cout << ans << '\n';
	}
}

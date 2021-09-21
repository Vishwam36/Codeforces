// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1574/problem/B#
// Decent

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
	
	int t = 0;
	cin >> t;

	while(t--)
	{
		int a, b, c, m;
		cin >> a >> b >> c >> m;

		vector<int> v = {a, b, c};
		sort(v.begin(), v.end());
		a = v[0], b = v[1], c = v[2];
		
		int minLimit = max(0, c-(a+b)-1);
		int maxLimit = a-1+b-1+c-1;

		if(m >= minLimit && m <= maxLimit)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

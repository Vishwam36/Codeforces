// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1632/problem/C
// Good

// REF : https://codeforces.com/blog/entry/99442

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int find_nb(int na, int b)
{
	int nb = 0;
	for(int i = 20; i >= 0; --i)
	{
		if(((b) & (1 << i)) != 0)
		{
			nb = nb | (1 << i);
		}
		else if(((na) & (1 << i)) != 0)
		{
			nb = nb | (1 << i);
			break;
		}
	}
	return nb;
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
		int a, b;
		cin >> a >> b;

		int mini = INT_MAX;
		for(int na = a; na <= b; ++na)
			mini = min(mini, na + (na | find_nb(na, b)));
		
		int ans = 1-a-b + mini;
		ans = min(ans, b-a);
		cout << ans << '\n';
	}
}

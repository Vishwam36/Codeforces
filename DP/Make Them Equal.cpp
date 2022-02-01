// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1633/problem/D
// Good

#include <bits/stdc++.h>
using namespace std;

#define ll long long
map<int, int> m;

void init()
{
	m[1] = 0;
	queue<int> q;
	q.push(1);
	int t = 0;

	while(!q.empty())
	{
		t++;
		int len = q.size();
		while(len--)
		{
			int curr = q.front(); q.pop();
			if(curr > 1000)
				continue;
			
			for(int i = 1; i <= curr; ++i)
			{
				int ne = curr / i;
				if(m.find(curr + ne) == m.end())
				{
					m[curr + ne] = t;
					q.push(curr + ne);
				}
			}
		}
	}
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

	init();
	int maxop = 0;
	for(auto it : m)
		maxop = max(maxop, it.second);

	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> b(n), c(n);
		for(int i = 0; i < n; ++i)
			cin >> b[i];
		for(int i = 0; i < n; ++i)
			cin >> c[i];
		
		k = min(k, n*maxop);
		vector<int> dp(k+1, 0);
		for(int i = 0; i < n; ++i)
			for(int j = k; j >= m[b[i]]; --j)
				dp[j] = max(dp[j], dp[j-m[b[i]]] + c[i]);
		
		cout << dp[k] << '\n';
	}
}

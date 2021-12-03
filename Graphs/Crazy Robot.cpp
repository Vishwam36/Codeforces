// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1613/problem/E
// Easy BFS

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
vector<string> v;
int n, m;

bool valid(int i, int j)
{
	return i >= 0 && j >= 0 && i < n && j < m;
}

bool canBePlus(int i, int j)
{
	int raste = 0;
	for(int k = 0; k < 4; ++k)
	{
		int ni = i + di[k];
		int nj = j + dj[k];

		if(valid(ni, nj) && v[ni][nj] == '.')
			raste++;
	}

	return raste <= 1;
}

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
		cin >> n >> m;
		v = vector<string> (n, string(m, ' '));

		int li, lj;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
			{
				cin >> v[i][j];
				if(v[i][j] == 'L')
				{
					li = i;
					lj = j;
				}
			}
		
		queue<pair<int, int> > q;
		q.push({li, lj});

		vector<vector<bool> > vis(n, vector<bool>(m, false));
		vis[li][lj] = 1;
		pair<int, int> p;
		int i, j;

		while(!q.empty())
		{
			p = q.front(); q.pop();
			i = p.first;
			j = p.second;

			for(int k = 0; k < 4; ++k)
			{
				int ni = i + di[k];
				int nj = j + dj[k];

				if(valid(ni, nj) && !vis[ni][nj] && v[ni][nj] == '.' && canBePlus(ni, nj))
				{
					q.push({ni, nj});
					vis[ni][nj] = 1;
					v[ni][nj] = '+';
				}
			}
		}

		for(auto s : v)
			cout << s << '\n';
    }
}

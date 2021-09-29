// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1579/problem/C
// Decent

#include <bits/stdc++.h>
using namespace std;

#define ll long 

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
		int n, m, k;
		cin >> n >> m >> k;

		vector<vector<char> > v(n, vector<char>(m));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				cin >> v[i][j];
		
		vector<vector<char> > copy(n, vector<char>(m, '.'));

		// {ci, cj} -> centre
		for(int ci = k; ci < n; ++ci)
		{
			for(int cj = k; cj <= m-1-k; ++cj)
			{
				bool f = 1; // tick possible
				int i = ci, j = cj;
				int len = -1;
				while(i >= 0 && j >= 0)
				{
					if(v[i][j] != '*')
						break;
					
					--i;
					--j;
					++len;
				}

				if(len < k)
					f = 0; // no tick possible

				i = ci, j = cj;
				int tempLen = -1;
				while(f && tempLen < len && i >= 0 && j < m)
				{
					if(v[i][j] != '*')
					{
						f = 0;
						break;
					}
					--i;
					++j;
					tempLen++;
				}

				if(len >= k && tempLen >= k) // Tick is possible
				{
					len = min(len, tempLen); // len = tick size
					tempLen = -1;
					i = ci, j = cj;
					while(tempLen < len && i >= 0 && j >= 0)
					{
						copy[i][j] = '*';
						--i;
						--j;
						tempLen++;
					}

					i = ci, j = cj;
					tempLen = -1;
					while(tempLen < len && i >= 0 && j < m)
					{
						copy[i][j] = '*';
						--i;
						++j;
						tempLen++;
					}
				}
			}
		}

		bool poss = 1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(v[i][j] != copy[i][j])
					poss = 0;
		
		if(poss)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1579/problem/B

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
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		vector<vector<int> > ans;
		vector<int> temp;
		
		for(int i = 0; i < n; ++i)
		{
			int idx = i, minEle = INT_MAX;
			for(int j = i; j < n; ++j)
			{
				if(a[j] < minEle)
				{
					minEle = a[j];
					idx = j;
				}
			}

			if(i != idx)
			{
				temp = {i+1, idx+1, idx-i};
				ans.push_back(temp);

				reverse(a.begin()+i, a.begin()+idx+1);
				reverse(a.begin()+i+1, a.begin()+idx+1);
			}
		}

		cout << ans.size() << endl;
		for(auto v : ans)
			cout << v[0] << " " << v[1] << " " << v[2] << endl;
	}
}

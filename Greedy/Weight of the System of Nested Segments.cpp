/**
 * @author Vishwam Shriram Mundada
 * @link https://codeforces.com/contest/1650/problem/C
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		ll n, m;
		cin >> m >> n;
 
		vector<pair<ll, ll> > v(n);
		map<ll, ll> idx;
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i].first >> v[i].second;
			idx[v[i].first] = i;
		}

		sort(v.begin(), v.end(), [](auto &a, auto &b){
			if(a.second == b.second)
				return a.first < b.first;
			return a.second < b.second;
		});

		while(v.size() > 2*m)
			v.pop_back();
		
		sort(v.begin(), v.end());
 
		ll sum = 0;
		for(int i = 0 ; i < 2*m; ++i)
			sum += v[i].second;
		
		cout << sum << '\n';
		for(int i = 0; i < m; ++i)
			cout << idx[v[i].first]+1 << ' ' <<  idx[v[2*m-i-1].first]+1 << '\n';
		cout << '\n';
	}
}

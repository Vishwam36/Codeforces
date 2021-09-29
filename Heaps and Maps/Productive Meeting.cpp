// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1579/problem/D
// Easy, priority queue

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
		
		vector<pair<int, int> > v;
		priority_queue<pair<int, int> > pq;
 
		for(int i = 0; i < n; ++i)
			if(a[i] > 0)
				pq.push({a[i], i});
		
		ll ans = 0;
		while(pq.size() > 1)
		{
			auto i = pq.top(); pq.pop();
			auto j = pq.top(); pq.pop();
 
			i.first--;
			j.first--;
 
			ans++;
			v.push_back({min(i.second,j.second), max(i.second,j.second)});
 
			if(i.first)
				pq.push(i);
			if(j.first)
				pq.push(j);
		}
 
		cout << ans << endl;
		for(auto p : v)
			cout << p.first+1 << " " << p.second+1 << endl;
	}
}

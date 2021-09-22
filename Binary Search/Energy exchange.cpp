// By Vishwam Shriram Mundada
// https://codeforces.com/problemset/problem/68/B
// Decent

#include <bits/stdc++.h>
using namespace std;

#define ll long long
double eps = 0.00000001;

bool can(int n, int k, vector<int>& a, double cand)
{
	double pos = 0, neg = 0;

	for(int i = 0; i < n; ++i)
	{
		if(a[i] >= cand)
			pos += a[i] - cand;
		else
			neg += cand - a[i];
	}

	if((pos*(100-k)/100) >= neg)
		return true;
	
	return false;
}

double solve(int n, int k, vector<int> v)
{
	double l = 0.0;
	double r = *max_element(v.begin(), v.end());
	double mid;

	while(r-l > eps)
	{
		mid = (l+r)/2;

		if(can(n, k, v, mid))
			l = mid;
		else
			r = mid;
	}

	return l;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int k, n;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	cout << fixed << setprecision(9) << solve(n, k, v) << endl;
}

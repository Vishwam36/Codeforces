/**
 * @author Vishwam Shriram Mundada
 * @link https://codeforces.com/contest/1650/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

void leftShift(vector<int> &a, int idx, int s)
{
	reverse(a.begin(), a.begin()+idx+1);
	reverse(a.begin(), a.begin()+(idx-s)+1);
	reverse(a.begin()+idx-s+1, a.begin()+idx+1);
}
 
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
 
		vector<int> ans(n, 0);
		
		for(int i = n-1; i >= 0; --i)
		{
			int num = i+1;
			int j = i;
			int s = 0;
			while(a[j] != num)
			{
				s++;
				j++;
				j %= (num);
			}
 
			leftShift(a, i, s);
			ans[i] = s;
		}
 
		for(auto i : ans)
			cout << i << ' ';
		cout << '\n';
	}
}

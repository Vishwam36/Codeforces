// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1625/problem/A
// Easy
// A

#include <bits/stdc++.h>
using namespace std;
 
string int_to_binary(int x, int l)
{
	string s;
	for(int i = 0; i < l; ++i)
	{
		if(((1 << i) & (x)) != 0)
			s.push_back('1');
		else
			s.push_back('0');
	}
	reverse(s.begin(), s.end());
	return s;
}
 
int binary_to_int(string &s)
{
	reverse(s.begin(), s.end());
	int ans = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '1')
			ans += (1 << i);
	}
	return ans;
}
 
int main()
{	
	int t;
	cin >> t;
	while(t--)
	{
		int n, l;
		cin >> n >> l;
 
		vector<string> nums(n);
		for(int i = 0; i < n; ++i)
		{
			int a;
			cin >> a;
			nums[i] = int_to_binary(a, l);
		}
 
		string ans;
		for(int i = 0; i < l; ++i)
		{
			int c0 = 0, c1 = 0;
			for(int j = 0; j < n; ++j)
			{
				if(nums[j][i] == '0')
					c0++;
				else
					c1++;
			}
 
			ans.push_back((c0 >= c1 ? '0' : '1'));
		}
 
		cout << binary_to_int(ans) << '\n';
	}
}

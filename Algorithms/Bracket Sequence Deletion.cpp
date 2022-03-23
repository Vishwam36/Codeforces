/**
 * @author : Vishwam Shriram Mundada
 * @link : https://codeforces.com/contest/1657/problem/C
 * @brief : decent
 * 
 * Main idea :
 * Only Two types of pallindromes are there
 * 1. ( ... (
 * 2. ) ... )
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
		ll n, op = 0;
		cin >> n;
 
		string s;
		cin >> s;
 
		stack<char> st;
 
		int i = 0;
		while(i < n)
		{
			if(i+1 < n && s[i] == '(' && s[i+1] == ')')
			{
				op++;
				i += 2;
				continue;
			}
 
			int j = i+1;
			while(j < n && s[j] != s[i])
				++j;
 
			if(j < n)
				op++;
			else
				break;
 
			i = j+1;
		}
 
		cout << op << ' ' << n-i << '\n';
	}
}

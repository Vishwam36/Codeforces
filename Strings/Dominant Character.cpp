// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1605/problem/C

/***
 * The following are all the possible minimal substrings (there aren't that many) which satisfy the given conditions: 
 * "aa", "aba", "aca", "abca", "acba", "abbacca", "accabba". Any other string that satisfies the condition contains at least one of these as a substring, 
 * and hence is not the optimal substring for the answer.
 * */

#include<bits/stdc++.h>
using namespace std;

bool can(int x, string &s, vector<vector<int> > &f)
{
    if(x == 0)
        return false;
    
	if(f[x-1][0] > f[x-1][1] && f[x-1][0] > f[x-1][2])
		return true;
	
	int n = s.size(), fa, fb, fc;
	for(int i = x; i < n; ++i)
	{
		fa = f[i][0] - f[i-x][0];
		fb = f[i][1] - f[i-x][1];
		fc = f[i][2] - f[i-x][2];
 
		if(fa > fb && fa > fc)
			return true;
	}
	return false;
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
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<vector<int> > f(n, vector<int>(3, 0));
 
		if(s[0] == 'a')
			f[0][0] = 1;
		else if(s[0] == 'b')
			f[0][1] = 1;
		else
			f[0][2] = 1;
		
		for(int i = 1; i < n; ++i)
		{
			f[i] = f[i-1];
			f[i][s[i]-'a']++;
		}

		if(can(2, s, f))
			cout << 2 << endl;
		else if(n >= 3 && can(3, s, f))
			cout << 3 << endl;
		else if(n >= 4 && can(4, s, f))
			cout << 4 << endl;
		else if(n >= 7 && can(7, s, f))
			cout << 7 << endl;
		else
			cout << -1 << endl;
	}
}

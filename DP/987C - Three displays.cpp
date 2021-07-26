// By Vishwam Shriram Mundada
// https://codeforces.com/problemset/problem/987/C
// Easy

/*
It is the middle of 2018 and Maria Stepanovna, who lives outside Krasnokamensk (a town in Zabaikalsky region), wants to rent three displays to highlight an important problem.

There are n displays placed along a road, and the i-th of them can display a text with font size si only. Maria Stepanovna wants to rent such three displays with indices 
i<j<k that  the font size increases if you move along the road in a particular direction. Namely, the condition si<sj<skshould be held.
The rent cost is for the i-th display is ci
Please determine the smallest cost Maria Stepanovna should pay.

Input
The first line contains a single integer n
(3≤n≤3000) — the number of displays.

The second line contains n
integers s1,s2,…,sn (1≤si≤109) — the font sizes on the displays in the order they stand along the road.

The third line contains n
integers c1,c2,…,cn (1≤ci≤108) — the rent costs for each display.

Output
If there are no three displays that satisfy the criteria, print -1. Otherwise print a single integer — the minimum total rent cost of three displays with indices
i<j<k such that si<sj<sk

Examples
Input
5
2 4 5 4 10
40 30 20 10 40
Output
90

Input
3
100 101 100
2 4 5
Output
-1

Input
10
1 2 3 4 5 6 7 8 9 10
10 13 11 14 15 12 13 13 18 13
Output
33

Note
In the first example you can, for example, choose displays 1, 4 and 5, because s1<s4<s5 (2<4<10), and the rent cost is 40+10+40=90.

In the second example you can't select a valid triple of indices, so the answer is -1.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
	int n;
	cin >> n;
	ll s[n];
	ll c[n];
	for(int i = 0; i < n; ++i)
	    cin >> s[i];
	   
	for(int i = 0; i < n; ++i)
	    cin >> c[i];
	
	ll dp2[n]; // min cost taking 2 together
	memset(dp2, -1, sizeof(dp2));
	for(int i = 0; i < n; ++i)
	{
	    dp2[i] = LLONG_MAX;
	    for(int j = i+1; j < n; ++j)
	    {
	        if(s[j] > s[i])
	        {
	            dp2[i] = min(dp2[i], c[i]+c[j]);
	        }
	    }
	}
	
	ll dp3[n]; // min cost taking 3 together
	memset(dp3, -1, sizeof(dp3));
	
	for(int i = 0; i < n; ++i)
	{
	    dp3[i] = LLONG_MAX;
	    for(int j = i+1; j < n; ++j)
	    {
	        if(s[j] > s[i] && dp2[j] != LLONG_MAX)
	        {
	            dp3[i] = min(dp3[i], c[i]+dp2[j]);
	        }
	    }
	}
	
	ll ans = LLONG_MAX;
	for(int i = 0; i < n; ++i)
	    ans = min(ans, dp3[i]);
	
	cout << (ans == LLONG_MAX ? -1 : ans) << endl;
	
	return 0;
}

// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1567/problem/C
// https://www.youtube.com/watch?v=7ou1zqT55LQ
// Trick

/*
Alice has just learned addition. However, she hasn't learned the concept of "carrying" fully — instead of carrying to the next column, she carries to the column 
two columns to the left.

Alice comes up to Bob and says that she has added two numbers to get a result of n. However, Bob knows that Alice adds in her own way. 
Help Bob find the number of ordered pairs of positive integers such that when Alice adds them, she will get a result of n. 
Note that pairs (a,b) and (b,a) are considered different if a≠b.

Input
The input consists of multiple test cases. The first line contains an integer t
(1≤t≤1000) — the number of test cases. The description of the test cases follows.

The only line of each test case contains an integer n
(2≤n≤10^9) — the number Alice shows Bob.

Output
For each test case, output one integer — the number of ordered pairs of positive integers such that when Alice adds them, she will get a result of n

Example
Input
5
100
12
8
2021
10000

Output
9
4
7
44
99

Note
In the first test case, when Alice evaluates any of the sums 1+9, 2+8, 3+7, 4+6, 5+5, 6+4, 7+3, 8+2, or 9+1, she will get a result of 100.
The picture below shows how Alice evaluates 6+4
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll t = 0, n, a, b;
	cin >> t;
	while(t--)
	{
		cin >> n;
		a = 0, b = 0;
		int pw = 1;
		while(n)
		{
			a = pw * (n % 10) + a;
			n /= 10;
			b = pw * (n % 10) + b;
			n /= 10;
			pw *= 10;
		}

		cout << (a+1) * (b+1) - 2 << endl;
	}
}

/**
 * @author Vishwam Shriram Mundada
 * @link https://codeforces.com/contest/1660/problem/D @endlink
 * @brief Good question 3D DP
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
		int n = 0;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		int neg = 0, twos = 0, maxtwos = 0;
		int start = -1, len = -1;
		queue<pair<int, int> > q;
		for(int i = 0; i < n; ++i)
		{
			if(a[i] == 0)
			{
				if(!q.empty() && neg % 2 == 0 && twos > maxtwos)
				{
					start = q.front().second;
					len = i-q.front().second;
					maxtwos = twos;
				}
				while(q.size() >= 1)
				{
					auto p = q.front(); q.pop();
					if(p.first == 2)
					{
						twos--;
					}
					else if(p.first == -2)
					{
						twos--;
						neg--;
					}
					else if(p.first == -1)
					{
						neg--;
					}

					if(!q.empty() && neg % 2 == 0 && twos > maxtwos)
					{
						start = q.front().second;
						len = i-q.front().second;
						maxtwos = twos;
					}
				}
				neg = 0;
				twos = 0;
			}
			else
			{
				q.push({a[i], i});
				if(a[i] == 2)
				{
					twos++;
				}
				else if(a[i] == -2)
				{
					twos++;
					neg++;
				}
				else if(a[i] == -1)
				{
					neg++;
				}

				if(!q.empty() && neg % 2 == 0 && twos > maxtwos)
				{
					start = q.front().second;
					len = i+1-q.front().second;
					maxtwos = twos;
				}
			}
		}

		if(neg % 2 == 0)
		{
			if(!q.empty() && twos > maxtwos)
			{
				start = q.front().second;
				len = n-q.front().second;
				maxtwos = twos;
			}
		}

		while(q.size() >= 1)
		{
			auto p = q.front(); q.pop();
			if(p.first == 2)
			{
				twos--;
			}
			else if(p.first == -2)
			{
				twos--;
				neg--;
			}
			else if(p.first == -1)
			{
				neg--;
			}
			if(!q.empty() && neg % 2 == 0 && twos > maxtwos)
			{
				start = q.front().second;
				len = n-q.front().second;
				maxtwos = twos;
			}
		}
		
		int end = start + len - 1;
		if(start == -1)
			cout << n << ' ' << '0' << '\n';
		else
			cout << start << ' ' << n-end-1 << '\n';
	}
}

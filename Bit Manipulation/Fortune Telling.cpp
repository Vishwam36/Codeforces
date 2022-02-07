/**
 * @author Vishwam Shriram Mundada
 * @date 2022-02-07
 * 
 * Observation : 
 * SUM operation and XOR operation work similarly
 *  - even + even = even, even ^ even = even
 *  - even + odd = odd, even ^ odd = odd
 *  - odd + odd = even, odd ^ odd = even
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
		ll n, x, y;
		cin >> n >> x >> y;
		ll sum = x, num;
		for(int i = 0; i < n; ++i)
		{
			cin >> num;
			sum += num;
		}

		if(sum % 2 == y % 2)
			cout << "Alice\n";
		else
			cout << "Bob\n";
	}
}

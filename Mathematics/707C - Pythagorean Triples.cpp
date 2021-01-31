// By Vishwam Shriram Mundada
// http://codeforces.com/contest/707/problem/C
// new concept
// Straight formula
// refer : https://www.geeksforgeeks.org/generate-pythagoras-triplet-single-integer/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n = 0, m = 0, k = 0;
    cin >> n;
    if(n == 1 || n == 2)
    {
        cout << -1;
        return 0;
    }
    if(n % 2 == 0)
    {
        cout << (n*n / 4) - 1 << " " << (n*n / 4) + 1;
        return 0;
    }
    else
    {
        cout << (n*n - 1) / 2 << " " << (n*n + 1) / 2;
        return 0;
    }
    cout << -1;
}

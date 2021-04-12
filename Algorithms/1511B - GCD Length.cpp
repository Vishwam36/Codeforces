// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1511/problem/B
// Easy

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        
        ll x = pow(10, a-1);
        ll y = pow(10, b-1);
        x += pow(10, c-1);
        cout << x << " " << y << endl;
    }
}

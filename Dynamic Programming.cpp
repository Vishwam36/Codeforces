// By Vishwam Shriram Mundada
// https://codeforces.com/contest/545/problem/C

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ll n = 0;
    cin >> n;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    ll x[n], h[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> h[i];
    }
    ll stay[n], left[n], right[n];
    stay[0] = 0;
    left[0] = 1;
    if(x[0] + h[0] < x[1])
    {
        right[0] = 1;
    }
    else
    {
        right[0] = 0;
    }
    for(int i = 1; i < n; ++i)
    {
        if(x[i] - h[i] > x[i-1])
        {
            if(x[i-1] + h[i-1] < x[i] - h[i])
            {
                left[i] = 1 + max(max(stay[i-1], right[i-1]), left[i-1]);
            }
            else
            {
                left[i] = 1 + max(left[i-1], stay[i-1]);
            }
        }
        else
        {
            left[i] = max(max(left[i-1], right[i-1]), stay[i-1]);
        }
        stay[i] = max(max(stay[i-1], left[i-1]), right[i-1]);
        if(x[i] + h[i] < x[i+1] || i == n-1)
        {
            right[i] = 1 + max(max(stay[i-1], right[i-1]), left[i-1]);
        }
        else
        {
            right[i] = max(max(left[i-1], stay[i-1]), right[i-1]);
        }
    }
    cout << max(max(right[n-1], left[n-1]), stay[n-1]);
}

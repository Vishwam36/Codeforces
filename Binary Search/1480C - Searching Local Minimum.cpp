// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1480/problem/C
// new one
/*
We maintain by binary search a range [l,r] which has a local minimum. Moreover, we assume that al−1>al and ar<ar+1. Initially, [l,r]=[1,n].

In each iteration, let m be the midpoint of l and r.

Case 1. If am<am+1, then the range becomes [l,m].

Case 2. If am>am+1, then the range becomes [m+1,r].

When l=r, we have found a local minimum al.
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n = 0;

int query(int x)
{
    cout << "? " << x << endl;
    fflush(stdout);
    cin >> x;
    return x;
}

int main()
{
    cin >> n;
    int l = 1, r = n, m = 0;
    int a[n+2];
    a[0] = INT_MAX;
    a[n+1] = INT_MAX;
    while(l < r)
    {
        m = (l + r) / 2;
        a[m] = query(m);
        a[m+1] = query(m+1);
        if(a[m] < a[m+1])
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << "! " << l << endl;
    fflush(stdout);
}

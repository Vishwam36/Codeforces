// By Vishwam Shriram Mundada
// http://codeforces.com/contest/732/problem/C
// consider all cases of arrival and leaving time and calculate their minimum meals required.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll max(ll a, ll b, ll c)
{
    if(a >= b && a >= c)
        return a;
    if(b >= a && b >= c)
        return b;
    return c;
}

int main()
{
    ll b, d, s;
    cin >> b >> d >> s;
    ll m = max(b, d, s);
    ll minMeals = 0;
    
    if(b != d && d != s && b != s)
    {
        minMeals = m + (m - 1) + (m - 1);
    }
        
    if(b == d)
    {
        if(b == max(b, d, s))
            minMeals = m + m + (m - 1);
            
        else
            minMeals = m + (m - 1) + (m - 1);
    }
    
    if(d == s)
    {
        if(s == max(b, d, s))
            minMeals = m + m + (m - 1);
            
        else
            minMeals = m + (m - 1) + (m - 1);
    }
    
    if(b == s)
    {
        if(s == max(b, d, s))
            minMeals = m + m + (m - 1);
        
        else
            minMeals = m + (m - 1) + (m - 1);
    }
    
    if(b == d && d == s)
    {
        minMeals = (m + m + m);
    }
    
    ll ans = minMeals - (b + d + s);
    
    if((minMeals - (b + d + s)) < 0)
    {
        ans = 0;
    }
    
    cout << ans << endl;
}

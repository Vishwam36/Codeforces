// By Vishwam Shriram Mundada
// http://codeforces.com/contest/807/problem/B
// logical brute force

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int pseudocode(int x)
{
    x = (x * 96 + 42) % 475;
    return x;
}

int main()
{
    int p = 0, x = 0, y = 0, ans = 0;
    cin >> p >> x >> y;
    int xNew = x;
    int temp = x;
    
    // checking for unsuccessful hacks from y to x
    while(xNew >= y)
    {
        temp = xNew;
        temp = (temp / 50) % 475;
        for(int i = 0; i < 25; ++i)
        {
            temp = pseudocode(temp);
            if(temp + 26 == p)
            {
                cout << ans;
                return 0;
            }
        }
        xNew -= 50;
    }
    
    xNew = x;
    
    // checking for cases having some suusessful operations
    // In these cases either we'll have only success hacks or success hacks with 1 unsuccessful hack
    while(1)
    {
        ans++;
        xNew += 50;
        temp = xNew;
        temp = (temp / 50) % 475;
        
        // if we find ans here then ('ans' successful hacks + 1 unsuccessful hack) will be required
        
        for(int i = 0; i < 25; ++i)
        {
            temp = pseudocode(temp);
            if(temp + 26 == p)
            {
                cout << ans;
                return 0;
            }
        }
        
        xNew += 50;
        temp = xNew;
        temp = (temp / 50) % 475;
        
        // if we find ans here then ('ans' successful hacks) will be required
        
        for(int i = 0; i < 25; ++i)
        {
            temp = pseudocode(temp);
            if(temp + 26 == p)
            {
                cout << ans;
                return 0;
            }
        }
    }
}

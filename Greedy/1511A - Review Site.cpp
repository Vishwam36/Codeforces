// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1511/problem/A#
// V Easy

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, up = 0, down = 0;
        cin >> n;
        
        int r[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> r[i];
            if(r[i] == 1)
                up++;
            
            else if(r[i] == 2)
                down++;
            
            else
                up++;
        }
        cout << up << endl;
    }
}

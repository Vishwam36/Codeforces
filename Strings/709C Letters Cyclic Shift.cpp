// By Vishwam Shriram Mundada
// https://codeforces.com/contest/709/problem/C
// simple

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    while(s[i] == 'a')
    {
        ++i;
    }
    if(i == n)
    {
        s[n-1] = 'z';
    }
    while(i < n)
    {
        if(s[i] == 'a')
        {
            break;
        }
        else
        {
            s[i] = s[i] - 1;
        }
        ++i;
    }
    cout << s;
}

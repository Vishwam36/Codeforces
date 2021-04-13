// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1511/problem/D
// more of logic, good logic

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    for(int i = 0; i < k; ++i)
    {
        s += 'a'+i;
        for(int j = i+1; j < k; ++j)
        {
            s += 'a'+i;
            s += 'a'+j;
        }
    }
    while(s.size() < n)
        s += s;
    
    s.resize(n);
    cout << s << endl;
}

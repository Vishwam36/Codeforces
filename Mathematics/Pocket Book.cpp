// By Vishwam Shriram Mundada
// 152 c
// https://codeforces.com/problemset/problem/152/C
/*
Observe that first position will have all those strings which are made by 
combinations of all different characters at all m positions in a string
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n=0, m=0;
    cin >> n >> m;
    vector<string> v;
    string str;
    for(ll i=0;i<n;++i)
    {
        cin >> str;
        v.push_back(str);
    }
    
    ll count = 1;
    set<char> s;
    for(ll i=0;i<m;++i)
    {
        s.clear();
        for(ll j=0;j<n;++j)
        {
            s.insert(v[j][i]);
        }
        count = count * s.size();
        count = count % 1000000007;
    }
    cout << count << endl;
    return 0;
}

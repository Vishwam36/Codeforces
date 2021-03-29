// By Vishwam Shriram Mundada
// https://codeforces.com/problemset/problem/520/B
// Decent

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    
    bool visited[20002] = {false};
    
    queue<pair<int, int> > q;
    q.push({n, 0});
    visited[n] = true;
    
    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        
        if(curr.first == m)
        {
            cout << curr.second << endl;
            return 0;
        }
        
        if(2*curr.first <= m*2 && !visited[2*curr.first])
        {
            visited[2*curr.first] = true;
            q.push({2*curr.first, curr.second+1});
        }
        if(curr.first-1 > 0 && !visited[curr.first-1])
        {
            visited[curr.first-1] = true;
            q.push({curr.first-1, curr.second+1});
        }
    }
}

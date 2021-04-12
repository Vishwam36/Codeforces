// By Vishwam Shriram Mundada
// https://codeforces.com/contest/1511/problem/C
// Decent

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, q, query;
    cin >> n >> q;
    int a[n];
    int arr[51];
    for(int i = 0; i < 51; ++i)
        arr[i] = -1;
    
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if(arr[a[i]] == -1)
            arr[a[i]] = i+1;
    }

    for(int i = 0; i < q; ++i)
    {
        cin >> query;
        cout << arr[query] << " ";
        for(int j = 1; j <= 50; ++j)
        {
            if(arr[j] < arr[query])
            {
                arr[j]++;
            }
        }
        arr[query] = 1;
    }
}

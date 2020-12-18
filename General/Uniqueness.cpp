// By Vishwam Mundada

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n=0, ans = 20000;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int l=0;l<n;++l)
    {
        set<int> s;
        map<int,int> count;
        for(int i=0;i<n;++i)
        {
            s.insert(a[i]);
            count[a[i]]++;
        }
        
        // If all are distinct then no need to check further
        if(s.size() == n)
        {
            cout<<0<<endl;
            return 0;
        }
        
        // Optimization
        for(int r=l;r<n;++r)
        {
            count[a[r]]--;
            if(count[a[r]] == 0)
            {
                s.erase(a[r]);
            }
            
            // if no. of unique elements == remaining elements 
            if(s.size() == (n-(r-l+1)))
            {
                ans = min(ans, r-l+1);
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}

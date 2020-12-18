// By Vishwam Mundada

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int k=0,n=0,sum=0;
    map<int, pair<int,int> > m;
    cin>>k;
    for(int i=0;i<k;++i)
    {
        sum=0;
        cin>>n;
        int a[n];
        for(int j=0;j<n;++j)
        {
            cin>>a[j];
            sum+=a[j];
        }
        for(int j=0;j<n;++j)
        {
            if(m.find(sum-a[j]) == m.end())
            {
                m[sum-a[j]] = {i+1, j+1};
            }
            else if(m[sum-a[j]].first != i+1)
            {
                cout<<"YES"<<endl;
                cout<<m[sum-a[j]].first<<" "<<m[sum-a[j]].second<<endl;
                cout<<i+1<<" "<<j+1<<endl;
                return 0;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<"NO"<<endl;
	return 0;
}

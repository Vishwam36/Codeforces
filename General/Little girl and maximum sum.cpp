// By Vishwam Mundada

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n=0,q=0,l=0,r=0;
    cin>>n>>q;
    int a[n];
    long long pre[n+1]={0};
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<q;++i)
    {
        cin>>l>>r;
        pre[l-1]++;
        pre[r]--;
    }
    long long sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=pre[i];
        pre[i]=sum;
    }
    
    sort(a,a+n,greater<int>());
    sort(pre,pre+n,greater<int>());
    
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=pre[i]*a[i];
    }
    cout<<ans<<endl;
	return 0;
}

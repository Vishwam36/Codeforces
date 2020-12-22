#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n=0, sum=0, ans=0, cnt=0;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		sum += a[i];
		a[i] = sum;
	}
	if(a[n-1] % 3 != 0)
	{
		cout<<0<<endl;
		return 0;
	}

	for(int i=0;i<n-1;++i)
	{
	    if(a[i] == 2*a[n-1]/3)
			ans+=cnt;
		if(a[i] == a[n-1]/3)
			cnt++;
	}
	cout<< ans <<endl;
	return 0;
}

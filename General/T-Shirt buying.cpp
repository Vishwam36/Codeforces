// By Vishwam Mundada

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n=0;
    cin>>n;
    int p[n], a[n], b[n];
    // create 3 different sets for 3 colors
    set<int> s1,s2,s3;
    set<int> :: iterator it;
    for(int i=0;i<n;++i)
    {
        cin>>p[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            s1.insert(p[i]);
        }
        else if(a[i]==2)
        {
            s2.insert(p[i]);
        }
        else
        {
            s3.insert(p[i]);
        }
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        if(b[i]==1)
        {
            s1.insert(p[i]);
        }
        else if(b[i]==2)
        {
            s2.insert(p[i]);
        }
        else
        {
            s3.insert(p[i]);
        }
    }
    
    int m=0, c=0;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        cin>>c;
        if(c==1)
        {
            if(s1.empty())
            {
                cout<<-1<<" ";
                continue;
            }
            it = s1.begin();
            int temp = *it;
            cout<<temp<<" ";
            s1.erase(temp);
            if(s2.find(temp) != s2.end())
            {
                s2.erase(temp);
            }
            else if(s3.find(temp) != s2.end())
            {
                s3.erase(temp);
            }
        }
        else if(c==2)
        {
            if(s2.empty())
            {
                cout<<-1<<" ";
                continue;
            }
            it = s2.begin();
            int temp = *it;
            cout<<temp<<" ";
            s2.erase(temp);
            if(s3.find(temp) != s3.end())
            {
                s3.erase(temp);
            }
            else if(s1.find(temp) != s1.end())
            {
                s1.erase(temp);
            }
        }
        else
        {
            if(s3.empty())
            {
                cout<<-1<<" ";
                continue;
            }
            it = s3.begin();
            int temp = *it;
            cout<<temp<<" ";
            s3.erase(temp);
            if(s2.find(temp) != s2.end())
            {
                s2.erase(temp);
            }
            else if(s1.find(temp) != s1.end())
            {
                s1.erase(temp);
            }
        }
    }
	return 0;
}

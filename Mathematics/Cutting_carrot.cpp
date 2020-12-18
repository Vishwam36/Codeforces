// By Vishwam Mundada
/*
Idea here is that, the topmost 1st horizontal line will cover area A/n (from vertex),
                               2nd horizontal line will cover area 2A/n, and so on....
*/

#include <bits/stdc++.h>
using namespace std;
 
int n=0,m=0;
 
int main() 
{
    int n=0,h=0;
    cin>>n>>h;
    double area, l;
    double theta = atan(2*h);
    area = h/2;
    int cuts = 0;
    while(cuts < n-1)
    {
        ++cuts;
        // calculating slope of triangle
        l = sqrt((h*cuts)/(2*n*sin(theta)*cos(theta)));
        cout<<setprecision(13)<<l*sin(theta)<<" ";
    }
	return 0;
}

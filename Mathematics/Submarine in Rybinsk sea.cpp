// By Vishwam Shriram Mundada
// 1195D1
// https://codeforces.com/problemset/problem/1195/D1

/*
Example
3
12 33 45
12 will come into picture 5 times in cases (a1,a1), (a1,a2), (a2,a1), (a1,a3), (a3,a1) 
observe that its contribution = n * (1*1000 + 1*100 + 2*10 + 2*1)
ans similar for all numbers
fun() is calculating contribution of a number
*/


#include <bits/stdc++.h>
using namespace std;
 
long long myPow(int base, int power)
{
    long long ans;
    if(power == 0)
    {
        return 1;
    }
    else if(power == 1)
    {
        return base;
    }
    if(power % 2 == 0)
    {
        ans = myPow(base, power/2);
        ans = (ans * ans) % 998244353;
    }
    else if(power % 2 == 1)
    {
        ans = myPow(base, power/2);
        ans = (base * ans * ans) % 998244353;
    }
    return ans % 998244353;
}
 
long long fun(long long a, long long number_of_digits)
{
    long long ans = 0;
    long long curr_digit, temp, digits_left = 2*number_of_digits;
    while(digits_left > 0)
    {
        temp = a % 10;
        ans += myPow(10, 2*number_of_digits - digits_left) * temp;
        ans = ans % 998244353;
        digits_left--;
        ans += myPow(10, 2*number_of_digits - digits_left) * temp;
        ans = ans % 998244353;
        digits_left--;
        
        a = a/10;
    }
    return ans % 998244353;
}
 
int main() 
{
    long long n=0;
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;++i)
        cin >> a[i];
        
    long long number_of_digits = 0, temp = a[0], ans=0;
    while(temp != 0)
    {
        number_of_digits++;
        temp = temp/10;
    }
    
    for(long long i=0;i<n;++i)
    {
        ans += fun(a[i], number_of_digits) * n;
        ans = ans % 998244353;
    }
    cout << ans << endl;
	return 0;
}

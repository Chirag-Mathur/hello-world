code chef sept long challenge div 2
/*https://www.codechef.com/SEPT20B/status/CHFNSWAP*/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll function1(ll sm)
{
    long double a=sqrtl(1ul + 4*(sm));
    a=a-1.0;
    a=a/2.0;
    ll fs=a;
    return fs;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        
        if(n==0 || n==1 || n==2)
        {    cout<<0<<"\n";
            continue;}
        
        ll total=n*(n+1)/2;
        
        if(total%2!=0)
        {
            cout<<"0"<<"\n";
            continue;
        }
        ll index=function1(total);
        
        ll ss=index*(index+1)/2;
        
        if(total/2==ss)
        {
            ll out=index*(index-1ul)/2l+((n-index)*(n-index-1ul))/2l+(n-index);
            cout<<out<<endl;
        }
        else
        {
            cout<<n-index<<endl;
        }
    }
}

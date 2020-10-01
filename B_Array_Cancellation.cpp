/*author : vidit shukla
           (valiant_vidit)*/
#pragma  GCC optimize("O3")
#include <bits/stdc++.h>
#define ll               long long int
#define bhaago           ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define loop(a,b,i)      for(ll i=a;i<b;i++)
#define loop1(a,b,i)     for(ll i=a;i>b;i--)
#define printclock       cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define endl              '\n'
#define yy               cout<<"YES"<<endl
#define nn               cout<<"NO"<<endl
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
const double pi = std::acos(-1);
using namespace std;
const ll mod = 1000000000+7;

ll power(ll x,ll y,ll md)  
{ll res=1;x=x%md;if(x==0)return 0;while(y>0){if(y&1)res=(res*x)%md;y=y>>1;x=(x*x)%md;}return res;} 

ll m_mul(ll a, ll b){a=a%mod;b=b%mod;return (a*b+mod)%mod;}
ll m_add(ll a,ll b){a=a%mod; b=b%mod;return (a+b+mod)%mod;}

ll spf[(ll)1e7+2]={0};
void siv()
{
spf[1]=1;
loop(1,1e7+2,i)
spf[i]=i;

loop(2,1e7+2,i)
spf[i]=2,i++;
for(ll i=3;i*i<(ll)1e7+2;i++)
{  
   if( spf[i]==i)
    for(ll j=i*i;j<(ll)1e7+2;j=j+i)
    if(spf[j]==j)spf[j]=i;
}

}
int main() {
      bhaago;
      // freopen("@iin.txt","r",stdin);
      // freopen("@output.txt","w",stdout);
    ll tc=1;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n; ll arr[n];
        loop(0,n,i)cin>>arr[i];
        ll ans=0;

        loop1(n-1,-1,i)
        {
            if(arr[i]<0)
            ans=ans+arr[i];
            else
            {
                if(ans<0)
                {
                    if(arr[i]>=abs(ans))ans=0;
                    else ans=ans+arr[i];
                }
            }
          //  cout<<ans<<" ";
        }
        cout<<abs(ans)<<endl;
    
        
    }
	// your code goes here
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define pb push_back
#define MOD 1000000007
#define sz5 100005
#define sz6 1000005
#define UP upper_bound
#define LB lower_bound
#define F first
#define S second
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>

void test_case(void) {
  int n,k,la,lb;
  cin>>n>>k;
  VI arr(n), cnt(104, 0);
  for(la=0;la<n;la++)
    cin>>arr[la], cnt[arr[la]]++;
  
  int dif=0;
  for(la=0;la<=100;la++){
    if(cnt[la]!=0)
      dif++;
  }
  int ans=0;
  if(k==1 && dif==1)
    cout<<1<<endl;
  else
  if(k==1 && dif>1)
    cout<<-1<<endl;
  else{
  while(dif>k){
    dif-=k;
    dif++;
    ans++;
  }
  if(dif!=0)
    ans++;
  cout<<ans<<endl;
  }
}

int main() {
  FAST

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int t;  cin>>t;
  for(int i=1;i<=t;i++){
    // cout<<"Case #"<<i<<": ";
    test_case();
  }

  return 0;
}

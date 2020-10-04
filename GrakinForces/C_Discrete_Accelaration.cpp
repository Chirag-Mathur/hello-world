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

bool poss(vector<double> &arr, double t, double l, ll n){
  ll la,lb;
  double curl=0, curr=l, time=t, s1=1, s2=1;
  for(la=1;la<=n;la++){
    double t=(arr[la]-curl)/s1;
    // cout<<t<<' '<<time<<endl;
    if(time<t){
      curl+=(time*s1);
      time=0;
      break;
    }
    curl=arr[la];
    time-=t;
    s1+=1.0;
    // cout<<t<<time<<' '<<s1<<' '<<curl<<endl;
  }
  curl+=(time*s1);

  time=t;
  for(la=n;la>=1;la--){
    double t=(curr-arr[la])/s2;
    if(time<t){
      curr-=(time*s2);
      time=0;
      break;
    }
    curr=arr[la];
    time-=t;
    s2+=1.0;
  }
  curr-=(time*s2);

  // cout<<t<<' '<<curl<<' '<<curr<<endl;

  if(curl>=curr)
    return true;
  return false;
}

void test_case(void) {
  ll n,last,la,lb;
  cin>>n>>last;
  vector<double> arr(n+1);
  for(la=1;la<=n;la++)
    cin>>arr[la];

  double ans=0, l=0, r=last;

  // poss(arr, 5, last, n);

  while((r-l)>=0.0000001){
    double mid=(l+r)/2;
    // cout<<l<<' '<<r<<endl;
    if(poss(arr, mid, last, n))
      ans=mid, r=mid;
    else
      l=mid;
  }

  printf("%.9lf\n", ans);
}

int main() {
  // FAST

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

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        float n,m;
        cin>>n>>m;
        long long int a,b;
        a = ceil(n/9);
        b = ceil(m/9);
        if(a < b){
            cout<<"0 "<<a<<endl;
        }
        else{
            cout<<"1 "<<b<<endl;
        }
    }
}

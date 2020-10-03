#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        long long int a[n],i,j,b[n];
        j=0;
        for(i=0;i<n;i++){
            cin>>a[i];
            if(k % a[i]==0){
                b[j] = a[i];
                j++;
            }
        }
        if(j==0){
            cout<<"-1"<<endl;
        }
        else{
        sort(b,b+j);
        cout<<b[j-1]<<endl;
        }
        
    }
}

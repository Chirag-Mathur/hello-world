#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int h,p,c1=0,c2=0;
        cin>>h>>p;
        while(h>0){
        if(p<=0){
            break;
        }
        h-=p;
        p=p>>1;
    }
    if(h<=0){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}
}

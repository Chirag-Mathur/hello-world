#include <vector>
#include <bits/stdc++.h>
using namespace std;

int SingleNumber(vector<int>& a){
    int x;
    unordered_map<int ,int > m;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
   
    // Hashing Using 
    unordered_map<int ,int >:: iterator it;
    for(it = m.begin();it!=m.end();it++)
        if(it->second == 1){
        cout<<it->first<<endl;
        x = it->first;
        }
    }
    return x;
}
int main()
{
        int n,val;
        cin>>n;
        vector<int> a(n);
            
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<SingleNumber(a)<<endl; 
    return 0;
}  

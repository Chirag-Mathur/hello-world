#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int sum = 0;
        
        int n = neededTime.size();
        
        int currColor = colors[0];
        priority_queue <int, vector<int>, greater<int>> pq;
        
        pq.push(neededTime[0]);
        int currCount = 1;
        
        int currMax = neededTime[0];
        for(int i = 1; i<n; i++){
            
            
            
            
            if(currColor == colors[i]){
                
                sum+= min(currMax, neededTime[i]);
                currMax = max(currMax, neededTime[i]);
                // currCount++;
                // pq.push(neededTime[i]);
                
            }else{
//                 while(pq.size() > 1){
//                     // cout<<pq.size()<<" ";
//                     sum+= pq.top();
//                     pq.pop();
//                     // cout<<sum<<" "<<colors[i]<<" "<<i<<endl;
//                 }
                
//                 pq = priority_queue <int, vector<int>, greater<int>>();
//                 pq.push(neededTime[i]);
//                 currCount= 1;
                currColor = colors[i];
                currMax = neededTime[i];
                
            }
        }
        
        // while(pq.size() > 1){
        //             sum+= pq.top();
        //             pq.pop();
        //         }
        
        return sum;
        
        
        
    }
};
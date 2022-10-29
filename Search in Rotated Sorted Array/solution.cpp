#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int l = 0, r = n-1;
        int mid;
        
        while(l<=r){
        
            mid = l + (r-l)/2;
            
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            
            if(nums[mid] == target){
                return mid;
            }
            
            if(target > nums[r]){
                
                if(nums[mid] < nums[l] || nums[mid] > target){
                    r = mid -1;
                }else{
                    l = mid+1;
                }
                
                
            }else{
                
                if(nums[mid] > nums[r] || nums[mid] < target){
                    l = mid+1;
                }else{
                    r = mid -1;
                }
                
            }
            
        }
        
        return -1;
        
    }
};
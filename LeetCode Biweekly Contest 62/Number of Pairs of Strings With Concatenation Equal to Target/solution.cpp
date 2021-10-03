// Author: Harsh Modi
// Question Link: https://leetcode.com/contest/biweekly-contest-62/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int ans = 0, n = nums.size();
        // ans will save number of pairs with the specified property
        
        map<string, int> freq;
        for (int i=0;i<n;i++) freq[nums[i]]++;
        
        string pre = "", suff = "";
        for (int i=0;i<(int)target.size();i++)
        {
            pre += target[i]; // target[0:i]
            suff = target.substr(i+1); // target[i+1:sz-1]
            if ( freq.find(pre) == freq.end() || freq.find(suff) == freq.end() ) 
            {
                //either prefix or the suffix doesn't exist in nums array
                continue;
            }
            
            // both prefix and suffix of the target string exists in the nums array
            // we also need to take care of the symmetric case when prefix == suffix
            // by subtracting one entry of the string
            ans += (freq[pre] - (pre == suff))*(freq[suff]);
            
        }
        
        return ans;
    }
};

// Time complexity: O(Nlog(M) + NK), N = size of target string, M = length of nums array, K = size of nums[i] string

// Space complexity: O(M*K) as we are using STL map with strings from nums array as keys and their frequency as value.
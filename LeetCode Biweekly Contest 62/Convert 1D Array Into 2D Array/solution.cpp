// Author: Harsh Modi
// Question Link: https://leetcode.com/contest/biweekly-contest-62/problems/convert-1d-array-into-2d-array/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        long long sz = original.size(); // size of the original array
        long long prod = (long long)m*(long long)n;
        
        vector<vector<int>> res;
        
        if (sz != prod)
        {
            // impossible to construct a mxn 2D array from the original
            return res;    
        }
        
        int s = 0, cnt = n;
        // s is the index in the original array from where the new row of the 2D matrix starts
        vector<int> v;
        while (s < sz)
        {
            v.clear();
            
            cnt = n;//number of elements in each row
            for (int j=s;cnt>0;j++,cnt--) v.push_back(original[j]);
            res.push_back(v);
            
            s += n;
        }
        return res;
    }
};

// Time complexity: O(N), N = size of the original array as we are traversing the array only once
// Space complexity: O(N) as we are constrycting a 2D (m x n) grid where m*n = size of the original array
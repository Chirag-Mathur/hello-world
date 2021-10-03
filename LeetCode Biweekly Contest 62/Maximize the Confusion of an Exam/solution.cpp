// Author: Harsh Modi
// Question Link: https://leetcode.com/contest/biweekly-contest-62/problems/maximize-the-confusion-of-an-exam/

int longestOnes(string& A, int k, char need) 
{
    int s = 0, e = 0, cnt = k, n = A.size();
    
    // s: start of the substring, e: end of the substring
    
    // represent the maximum number of consecutive Ts of Fs.
    int mxlen = 0;
    
    // two-pointer approach
    while (e < n)
    {
        if (A[e] == need) 
        {
            // current character is what we need the update the mxlen and continue
            mxlen = max(mxlen, e-s+1);
            e++;
        }
        else
        {
            // current character is not what we need
            if (cnt > 0)
            {
                // we are able to change it to the need character
                cnt--;
            }
            else
            {
                // we don't have enough cnt to change it, so we try to remove unwanted character from the start of the substring
                // in order to increase cnt's value.
                while (s < e && cnt <= 0)
                {
                    if (A[s] != need) cnt++;
                    s++;
                }
                
                // use it to change current character
                cnt--;
                
            }
            mxlen = max(mxlen, e-s+1);
            e++;
        }
    }
    
    return mxlen;
}

class Solution {
public:
    int maxConsecutiveAnswers(string str, int k) 
    {
        // try to replace 'F' to 'T'
        int mx1 = longestOnes(str,k, 'T');
        
        // try to replace 'T' to 'F'
        int mx2 = longestOnes(str,k, 'F');
        
        
        return max(mx1, mx2);
    }
};

// Time complexity: O(N), N = length of the string. As we are treversing the string only 2 times

// Space complexity: O(1)
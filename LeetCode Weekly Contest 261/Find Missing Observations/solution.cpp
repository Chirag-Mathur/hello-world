// ques link - https://leetcode.com/contest/weekly-contest-261/problems/find-missing-observations/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        // size of rolls, sum, missingSum
        int m=rolls.size(), sum=0, missingSum=0;

        // the sum of values of m throws
        for(int i=0;i<m;i++) {
            sum+=rolls[i];
        }

        // the missing sum of n throws of dice
        missingSum=mean*(n+m)-sum;

        // taking an answer vector
        vector<int>ans;

        // if the missing sum will be less than n or greater than 6*n
        // no any answer will be valid so returning empty vector
        if(missingSum<n || missingSum>6*n)
            return ans;

        // taking remaining sum if the missingSum will not be a factor of two
        int remainingSum=missingSum%n;

        // first pushing missingSum/n to the answer vector
        for(int i=0;i<n;i++) {
            ans.push_back(missingSum/n);
        }

        // the remanining sum will be less than n to adding 1 to every element of answer vector
        // to make it equal to missing sum
        for(int i=0;i<remainingSum;i++)
            ans[i]+=1;


        return ans;   
    }
};
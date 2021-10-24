// ques link - https://leetcode.com/contest/weekly-contest-261/problems/minimum-moves-to-convert-string/

class Solution {
public:
    int minimumMoves(string s) {

        // initialize answer to 0
        int ans = 0, l = s.length(), i = 0;

        // loop till the length of string
        while(i<l) {

            // if the character at (i)th position is 'X' then no need to check for
            // two (i+1)th and (i+2)th position as we have to take the three consecutive position
            if(s[i]=='X') {

                // increase the value of of i by 3
                i+=3;

                // increase the count of moves/answer
                ans++;

            } else {

                // if the character at (i)th position will be 'O' then no need to change anything
                // we just increase the i by 1
                i++;
            }
        }

        // return the answer(or the count of moves)
        return ans;
    }
};
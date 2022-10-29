#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        
        for(int i = 0; i<magazine.size(); i++){
            freq[magazine[i]-'a']++;
        }
        
        for(int i = 0; i<ransomNote.size(); i++){
            freq[ransomNote[i]-'a']--;
            if(freq[ransomNote[i]-'a']<0){
                return false;
            }
        }
        
        return true;
        
    }
};
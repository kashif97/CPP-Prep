class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;
        for(char c : t){
            if(sIndex<s.size() && s[sIndex] == c){
                sIndex++;
            }
        }
        if(sIndex == s.size()){
            return true;
        }
        return false;
    }
};
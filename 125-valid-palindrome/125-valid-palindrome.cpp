class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.length()-1; i < s.length(), j > 0; ++i, --j){
            while(!isalnum(s[i]) and i < s.length()){
                ++i;
            }
            while(!isalnum(s[j]) and j > 0){
                --j;
            }
            
            if(j == 0 or i == s.length()){
                break;
            }
            
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
        
        }
        return true;
    }
};
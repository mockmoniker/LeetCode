class Solution {
public:
    int firstUniqChar(string s) {
        
        int letters[26] = {0};
        
        for(int i = 0; i < s.length(); ++i){
            ++letters[s[i]-'a'];
        }
        
        for(int i = 0; i < s.length(); ++i){
            if(letters[s[i]-'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // prefix count
        string result = "";
        
        // shortest word index and length
        int short_word_i = 0;
        int short_word_l = INT_MAX;
        
        // find shortest word
        for(int i = 0; i < strs.size(); ++i){
            if(strs[i].length() < short_word_l){
                short_word_l = strs[i].length();
                short_word_i = i;
            }
        }
        
        // check every char of every string matches the shortest, return on miss
        for(int i = 0; i < short_word_l; ++i){
            for(int j = 0; j < strs.size(); ++j){
                if(strs[short_word_i][i] != strs[j][i]){
                    return result;
                }
            }
            result.push_back(strs[short_word_i][i]);
        }
        
        return result;
    }
};
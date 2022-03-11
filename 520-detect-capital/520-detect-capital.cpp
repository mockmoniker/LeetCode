class Solution {
public:
    bool detectCapitalUse(string word) {
        int targetCase = 0; // 0: any, 1 lower, 2 upper
        
        if(word.length() == 1) return true;
        
        if(isupper(word[0])){
            targetCase = 0;
        }else{
            targetCase = 1;
        }
        
        for(int i = 1; i < word.length(); ++i){
            if(targetCase == 0){
                targetCase = isupper(word[i]) ? 2 : 1;
                continue;
            }
            
            if(targetCase == 1 and isupper(word[i])) return false;
            if(targetCase == 2 and !isupper(word[i])) return false;
            
        }
        
        return true;
    }
};
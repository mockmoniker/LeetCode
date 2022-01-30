class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int dist = wordsDict.size()-1;
        int count = 1;
        int nextWord = 0;
        
        int index = 0;
        while(nextWord == 0){
            if(wordsDict[index] == word1){
                nextWord = 2;
            }
            if(wordsDict[index] == word2){
                nextWord = 1;
            }
            ++index;
        }
        
        for(int i = index; i < wordsDict.size(); ++i){
            if(wordsDict[i] == word1){
                if(nextWord == 1){
                    dist = min(dist, count);
                    nextWord = 2;
                }
                count = 0;
            }
            
            if(wordsDict[i] == word2){
                if(nextWord == 2){
                    dist = min(dist, count);
                    nextWord = 1;
                }
                count = 0;
            }
            ++count;
        }
        return dist;
    }
};
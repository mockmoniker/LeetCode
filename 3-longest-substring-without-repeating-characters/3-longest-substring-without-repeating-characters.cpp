class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int m = 0, c = 0;
        
        for(int i = 0; i < s.length(); ++i){
            if(umap.count(s[i])){ // found a duplicate
                if(umap[s[i]] < i-c){ // if duplicate's index is greater than {count} indicies away
                    ++c;
                }else{
                    c = i-umap[s[i]]; // set count to length since last duplicate
                    
                }
                // in either case, update the new character's index
                umap.erase(s[i]);
                umap.insert({s[i], i});
            }else{ // not a duplicate
                umap.insert({s[i], i});
                c++; 
            }
            m = max(m, c);
        }
        return m;
    }
};
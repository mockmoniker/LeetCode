class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        
        for(int i = 0; i < nums.size(); ++i){
            umap.insert({nums[i], i});
        }
        
        for(int j = 0; j < nums.size(); ++j){
            if(umap.count(target - nums[j]) ){
                if(umap[target - nums[j]] != j){
                    return {umap[target - nums[j]], j};
                }
            }
        }
        
        return {0,0};
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> umap;
        int k = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(umap.count(nums[i])){
                continue;
            }
            umap.insert({nums[i], i});
            nums[k++] = nums[i];
        }
        
        return k;
    }
};
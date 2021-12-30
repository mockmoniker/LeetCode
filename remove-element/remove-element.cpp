class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // counter for remaining numbers
        int k = 0;
        
        // traverse array, moving every non val number to beginning, keeping track with k
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val){
                nums[k] = nums[i];
                ++k;
            }
        }
        
        return k;
    }
};
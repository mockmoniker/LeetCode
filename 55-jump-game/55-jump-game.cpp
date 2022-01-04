class Solution {
public:
    
    
    bool canJump(vector<int>& nums) {
        int target = nums.size()-1;
        bool answer = true;
        for(int i = nums.size()-1; i > 0; --i){
            if(i+nums[i-1] <= target){
                answer = false;
            }else{
                answer = true;
                target = i-1;
            }
            
        }
        return answer;
    }
};
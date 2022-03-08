class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int index = 0;
        
        // case 1 element
        if(left == right){
            if(target <= nums[left]){
                return left;
            }
            
            return left + 1;
        }
        
        // case 0 elemnt
        if(right == 0){
            return 0;
        }
        
        while(left < right){
            
            // get index
            index = (left + right) / 2;
            
            // found target
            if(target == nums[index]){
                return index;
            }
            
            // last two numbers
            if(index == left){
                
                // target if left or lower
                if(target <= nums[left]){
                    return left;
                }
                
                // target is at right
                if(target <= nums[right]){
                    return right;
                }
                
                // target is out of array
                return right + 1;
            }
            
            // left of target
            if(target > nums[index]){
                left = index;
            }
            
            // right of target
            if(target < nums[index]){
                right = index;
            }
        }
        
        return index;
    }
};
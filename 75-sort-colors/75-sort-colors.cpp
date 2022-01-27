class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                ++red;
            }else if(nums[i] == 1){
                ++white;
            }else{
                ++blue;
            }
        }
        
        int index = 0;
        while(red){
            nums[index] = 0;
            --red;
            ++index;
        }
        while(white){
            nums[index] = 1;
            --white;
            ++index;
        }
        while(blue){
            nums[index] = 2;
            --blue;
            ++index;
        }
    }
};
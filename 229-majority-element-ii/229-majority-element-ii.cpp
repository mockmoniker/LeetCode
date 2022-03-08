class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> map;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); ++i){
            
            if(map[nums[i]] == INT_MAX){
                continue;
            }
   
            ++map[nums[i]];
            
            if(map[nums[i]] > nums.size()/3){
                result.push_back(nums[i]);
                map[nums[i]] = INT_MAX;
            }
        }
        
        return result;
    }
};
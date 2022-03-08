class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int done = false;
        int index = digits.size() - 1;
        
        while(!done and index >= 0){
            ++digits[index];
            
            if(digits[index] == 10){
                digits[index] = 0;
                --index;
            }else{
                done = true;
            }
        }
        
        if(index < 0){
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool targetFound = false;
        
        int x = 0;
        int y = matrix.size()-1;
        while(x < matrix[0].size() and y >= 0){
            if(matrix[y][x] < target){
                ++x;
                continue;
            }
            if(matrix[y][x] > target){
                --y;
                continue;
                    
            }
            return true;
        }
        
        return targetFound;
    }
};
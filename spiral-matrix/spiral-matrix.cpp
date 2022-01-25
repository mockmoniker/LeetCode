class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        
        int top = 0;
        int right = matrix[0].size()-1;
        int bottom = matrix.size()-1;
        int left = 0;
        
        while(1){
            // traverse right across top row
            for(int i = left; i <= right; ++i){
                ret.push_back(matrix[top][i]);
            }
            ++top;

            if(top > bottom){
                break;
            }

            // traverse down right column
            for(int i = top; i <= bottom; ++i){
                ret.push_back(matrix[i][right]);
            }
            --right;

            if(left > right){
                break;
            }
            
            // traverse left across bottom row
            for(int i = right; i >= left; --i){
                ret.push_back(matrix[bottom][i]);
            }
            --bottom;

            if(top > bottom){
                break;
            }

            // travesre up left column
            for(int i = bottom; i >= top; --i){
                ret.push_back(matrix[i][left]);
            }
            ++left;
            
            if(left > right){
                break;
            }
        }
        
        return ret;
    }
};
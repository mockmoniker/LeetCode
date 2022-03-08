class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result = {{1}, {1,1}};
        
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1,1}};
        
        for(int i = 2; i < numRows; ++i){
            vector<int> prev_row = result[i-1];
            vector<int> curr_row = {1};
            for(int j = 0; j < prev_row.size()-1; ++j){
                curr_row.push_back(prev_row[j] + prev_row[j+1]);
            }
            curr_row.push_back(1);
            result.push_back(curr_row);
        }
        
        return result;
    }
};
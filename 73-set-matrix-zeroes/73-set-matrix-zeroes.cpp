class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int, int> rows;
        map<int, int> columns;
        
        for(int x = 0; x < matrix[0].size(); ++x){
            for(int y = 0; y < matrix.size(); ++y){
                if(matrix[y][x] == 0){
                    rows[y]++;
                    columns[x]++;
                }
            }
        }
        
        for(int x = 0; x < matrix[0].size(); ++x){
            for(int y = 0; y < matrix.size(); ++y){
                if(rows[y] or columns[x]){
                    matrix[y][x] = 0;
                }
            }
        }
    }
};
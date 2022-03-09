class Solution {
public:
    
//     int x_limit;
//     int y_limit;
//     int result = INT_MAX;
    
//     void myfunc(int x, int y, int sum, vector<vector<int>> grid){
        
//         sum += grid[y][x];
        
//         // end condition
//         if(x == x_limit and y == y_limit){
//             result = min(result, sum);
//             return;
//         }
        
//         if(x != x_limit){
//             myfunc(x+1, y, sum, grid);
//         }
        
//         if(y != y_limit){
//             myfunc(x, y+1, sum, grid);
//         }
        
//         return;
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int x = 0;
        int y = 0;
        
        for(x = 0; x < grid[0].size(); ++x){
            for(y = 0; y < grid.size(); ++y){
                int top = 999;
                int left = 999;
                if(x != 0){
                    left = grid[y][x-1];
                }
                if(y != 0){
                    top = grid[y-1][x];
                }
                
                if(x == 0 and y == 0){
                    continue;
                }
                
                grid[y][x] = min(grid[y][x] + top, grid[y][x] + left);
            }
        }
        
        return grid[y-1][x-1];
    }
};
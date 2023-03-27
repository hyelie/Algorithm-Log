// Runtime 7 ms Beats 90.29%
// Memory 9.5 MB Beats 98.74%

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int c = 1; c<n; c++){
            grid[0][c] += grid[0][c-1];
        }
        for(int r = 1; r<m; r++){
            grid[r][0] += grid[r-1][0];
        }

        for(int r = 1; r<m; r++){
            for(int c = 1; c<n; c++){
                grid[r][c] += min(grid[r-1][c], grid[r][c-1]);
            }
        }

        return grid[m-1][n-1];
    }
};
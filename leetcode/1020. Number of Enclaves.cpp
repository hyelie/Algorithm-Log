// Runtime 66 ms Beats 95.6%
// Memory 33 MB Beats 33.12%

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    void DFS(int r, int c){
        grid[r][c] = 0;
        for(int i = 0; i<4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == 1){
                grid[nr][nc] = 0;
                DFS(nr, nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& g) {
        grid = g;
        m = grid.size(); n = grid[0].size();

        for(int i = 0; i<m; i++){
            if(grid[i][0] == 1) DFS(i, 0);
            if(grid[i][n-1] == 1) DFS(i, n-1);
        }
        for(int j = 0; j<n; j++){
            if(grid[0][j] == 1) DFS(0, j);
            if(grid[m-1][j] == 1) DFS(m-1, j);
        }

        int answer = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                answer += grid[i][j];
            }
        }
        return answer;
    }
};

// Runtime 87 ms Beats 30.50%
// Memory 35.1 MB Beats 14.72%

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<bool>> visited; 
    vector<bool> isEnclave;
    vector<int> islandCount;
    void DFS(int r, int c){
        if(r == 0 || r == m-1 || c == 0 || c == n-1) isEnclave[isEnclave.size()-1] = false;
        islandCount[islandCount.size()-1]++;
        
        for(int i = 0; i<4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(0 <= nr && nr < m && 0 <= nc && nc < n && !visited[nr][nc] && grid[nr][nc] == 1){
                visited[nr][nc] = true;
                DFS(nr, nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& g) {
        grid = g;
        m = grid.size(); n = grid[0].size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        visited = v;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    isEnclave.push_back(true); islandCount.push_back(0);
                    visited[i][j] = true;
                    DFS(i, j);
                }
            }
        }

        int answer = 0;
        for(int i = 0; i<isEnclave.size(); i++){
            if(isEnclave[i]) answer += islandCount[i];
        }
        return answer;
    }
};
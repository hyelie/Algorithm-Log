// Runtime 17 ms Beats 37.16%
// Memory 11.8 MB Beats 19.3%

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

typedef pair<int, int> pii;

class Solution {
public:
    int visited[101][101];
    int maxr, maxc;
    vector<vector<int>> grid;
    vector<vector<pii>> islands;
    int cnt = 0;
    void DFS(int r, int c){
        for(int i = 0; i<4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(0 <= nr && nr < maxr && 0 <= nc && nc < maxc && visited[nr][nc] == false && grid[nr][nc] == 0){
                visited[nr][nc] = true;
                islands[cnt].push_back({nr, nc});
                DFS(nr, nc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grids) {
        grid = grids;
        maxr = grid.size(); maxc = grid[0].size();
        for(int i = 0; i<maxr; i++){
            for(int j = 0; j<maxc; j++){
                visited[i][j] = false;
            }
        }
        islands.resize(1);
        

        for(int i = 0; i<maxr; i++){
            for(int j = 0; j<maxc; j++){
                if(visited[i][j] == false && grid[i][j] == 0){
                    visited[i][j] = true;
                    islands[cnt].push_back({i, j});
                    DFS(i, j);
                    cnt++;
                    islands.push_back({});            
                }
            }
        }

        int answer = 0;
        for(vector<pii>& island : islands){
            bool isClosed = true;
            for(pii p : island){
                if(p.first == 0 || p.first == maxr-1 || p.second == 0 || p.second == maxc-1){
                    isClosed = false;
                }
            }
            if(isClosed) answer++;
        }
        return answer-1;
    }
};
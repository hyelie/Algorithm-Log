// Runtime 62 ms Beats 91.36%
// Memory 30.2 MB Beats 86.75%

/*
이렇게 풀었을 때 시간 내에 풀림을 어떻게 보장하는가?
모든 0지점부터 BFS 탐색을 시작한다. 단, 갱신할 수 없는 위치라면(다른 0으로부터 더 가깝다면) 그곳은 탐색하지 않는다.
하나의 최적화를 추가하는데, 0에서 BFS를 각각 수행하는 것이 아니라(그렇게 하면 BFS가 10000번 수행될 수도 있다.)
모든 0을 queue에 넣고 한 칸씩 BFS 해 나가는 것이다. 그러면 0에 인접한 칸은 그 개수만큼 방문하지만, 다음 갱신할 칸은 1번씩만 방문한다.
*/

typedef pair<int, int> pii;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), INF = 10001;
        vector<vector<int>> answer(m, vector<int>(n, INF));
        queue<pii> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                     answer[i][j] = 0;
                     q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            pii cur = q.front(); q.pop();
            for(int i = 0; i<4; i++){
                int nr = cur.first + dr[i];
                int nc = cur.second + dc[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n && answer[cur.first][cur.second] + 1 < answer[nr][nc]){
                    answer[nr][nc] = answer[cur.first][cur.second] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return answer;
    }
};
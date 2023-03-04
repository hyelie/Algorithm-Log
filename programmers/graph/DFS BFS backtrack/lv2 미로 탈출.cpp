#include <string>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
bool visited[101][101];
vector<string> Maps;
int maxr, maxc;
struct Search{
    int r, c, dist = 0;  
};

void initVisited(){
    for(int r = 0; r<maxr; r++){
        for(int c = 0; c<maxc; c++){
            visited[r][c] = false;
        }
    }
}

int BFS(Search start, Search end){
    queue<Search> q;
    q.push(start);
    visited[start.r][start.c] = true;
    
    while(!q.empty()){
        Search cur = q.front(); q.pop();
        int cr = cur.r, cc = cur.c, cd = cur.dist;
        if(cr == end.r && cc == end.c) return cd;
        for(int i = 0; i<4; i++){
            int nr = cr + dr[i], nc = cc + dc[i];
            if(0 <= nr && nr < maxr && 0 <= nc && nc < maxc && !visited[nr][nc] && Maps[nr][nc] != 'X'){
                Search next; next.r = nr; next.c = nc; next.dist = cd + 1;
                visited[nr][nc] = true;
                q.push(next);
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    Maps = maps;
    maxr = maps.size(); maxc = maps[0].size();
    
    Search start, lever, exit;
    for(int r = 0; r < maxr; r++){
        for(int c = 0; c<maxc; c++){
            if(maps[r][c] == 'S'){
                start.r = r; start.c = c;
            }
            else if(maps[r][c] == 'E'){
                exit.r = r; exit.c = c;
            }
            else if(maps[r][c] == 'L'){
                lever.r = r; lever.c = c;
            }
        }
    }
    
    initVisited();
    int start2lever = BFS(start, lever);
    
    initVisited();
    int lever2exit = BFS(lever, exit);
    
    if(start2lever == -1 || lever2exit == -1) return -1;
    
    return start2lever + lever2exit;
}
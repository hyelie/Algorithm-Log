#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 순서대로 n, m, r, c, k
int maxr, maxc, exitr, exitc, targetdist;
string IMPOSSIBLE = "impossible";
string result = IMPOSSIBLE;

int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};
vector<string> direction = {"d", "l", "r", "u"};

int getDist(int r1, int c1, int r2, int c2){
    return abs(r1 - r2) + abs(c1 - c2);
}

void DFS(int curDepth, int curr, int curc, string path){
    if(curDepth == targetdist){ // k만큼 탐색한 경우
        if(curr == exitr && curc == exitc){
            if(result == IMPOSSIBLE) result = path;
            else return;
        }
        return;
    }
    if(curDepth > targetdist) return;
    
    for(int i = 0; i<4; i++){
        int nextr = curr + dr[i], nextc = curc + dc[i];
        if(0 <= nextr && nextr < maxr && 0 <= nextc && nextc < maxc){
            // pruning
            if(getDist(nextr, nextc, exitr, exitc) > (targetdist - curDepth)) continue;
            
            // deeper
            DFS(curDepth + 1, nextr, nextc, path + direction[i]);
            if(result != IMPOSSIBLE) return;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    
    // initialize
    x--; y--; r--; c--; // zero-indexing
    maxr = n; maxc = m; exitr = r; exitc = c; targetdist = k;
    
    if((getDist(x, y, exitr, exitc) % 2) != (k %= 2)) return IMPOSSIBLE;
    
    DFS(0, x, y, "");
    return result;
}

/*
BFS? DFS?
각 위치에서 경우의 수 : 4
vertex가 각 위치마다 2개라고 두자고.
그러면 V = 5000, E = 각 위치마다 8개니 40000
DFS나 BFS 경우 시간은 충분함

BFS 하는 경우 : visited 관리 귀찮을 듯
DFS로 하자

*/
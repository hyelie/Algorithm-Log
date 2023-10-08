// 10분에 다 풀었음.
/*
간단한 BFS 문제. 주어진 대로 구현하면 됨.
*/

#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct info{
    int r, c;
};

int maxn;
vector<int> visited; // visited[i] : i번 computer 썼는지 여부
vector<vector<int>> connected; // connected[i][j] : i번과 j번이 연결되어 있으면 true, else false

// n번째 computer에서 BFS
void BFS(int n){
    queue<int> q;
    q.push(n);
    visited[n] = true;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        visited[cur] = true;
        
        for(int next = 0; next<maxn; next++){
            if(!visited[next] && connected[cur][next]){
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> visited_init(n+1, false); 
    visited = visited_init;
    connected = computers;
    maxn = n;
    
    int answer= 0;
    for(int i =0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            BFS(i);
            answer++;
        }
    }
    return answer;
}
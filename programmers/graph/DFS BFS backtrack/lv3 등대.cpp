using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> edges;
vector<bool> visited;

// .first : curV를 색칠했을 때 색칠 최소값
// .second : curV를 색칠하지 않았을 때 색칠 최소값
pii DFS(int curV){
    visited[curV] = true;
    
    pii cur = {1, 0}; // if leaf then return [1, 0]
    
    for(int adj : edges[curV]){
        if(!visited[adj]){
            pii childResult = DFS(adj);
            // curV를 색칠하지 않았다면 child는 색칠되어야만 함
            cur.second += childResult.first;
            // curV를 색칠했다면 child는 색칠되든 말든 상관없음
            cur.first  += min(childResult.first, childResult.second);
        }
    }
    
    return cur;
}

int solution(int n, vector<vector<int>> lighthouse) {
    // initialize
    edges.resize(n+1);
    for(vector<int> vi : lighthouse){
        edges[vi[0]].push_back(vi[1]);
        edges[vi[1]].push_back(vi[0]); 
    }
    visited.resize(n+1);
    fill(visited.begin(), visited.end(), false);
    
    pii result = DFS(1);
    
    return min(result.first, result.second);
}
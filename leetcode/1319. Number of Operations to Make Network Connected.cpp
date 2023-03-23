// 1st solution
// Runtime 139 ms Beats 61.43%
// Memory 44.1 MB Beats 53.23%

class Solution {
public:
    vector<int> parent;
    int find(int v){
        if(parent[v] == v) return v;

        parent[v] = find(parent[v]);
        return parent[v];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;

        int needless = 0;
        for(vector<int> connection : connections){
            int rx = find(connection[0]), ry = find(connection[1]);
            if(rx != ry){
                parent[rx] = ry;
            }
            else{
                needless++; // 이미 같은 그룹
            }
        }

        int numGroups = -1;
        for(int i = 0; i<n; i++){
            if(find(i) == i) numGroups++;
        }

        if(numGroups > needless) numGroups = -1;
        return numGroups;
    }
};

// 2nd solution
// Runtime 145 ms Beats 52.54%
// Memory 51 MB Beats 41.15%

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> edges; // edges[i] : i에서 출발하는 vertex의 도착 vertex vector
    void DFS(int v){        
        for(int w : edges[v]){
            if(!visited[w]){
                visited[w] = true;
                DFS(w);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numConnections = connections.size();
        if(numConnections < n-1) return -1;

        edges.resize(n);
        for(vector<int> &connection : connections){
            edges[connection[0]].push_back(connection[1]);
            edges[connection[1]].push_back(connection[0]);
        }
        visited.resize(n);
        fill(visited.begin(), visited.end(), false);

        int numGroups = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                numGroups++;
                visited[i] = true;
                DFS(i);
            }
        }

        return numGroups - 1;
    }
};
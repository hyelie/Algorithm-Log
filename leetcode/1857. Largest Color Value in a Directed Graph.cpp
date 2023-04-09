class Solution {
public:
    int n;
    vector<vector<int>> edges;
    vector<int> num_income;
    int largestPathValue(string colors, vector<vector<int>>& e) {
        // initialize
        n = colors.size();
        edges.resize(n);
        num_income.resize(n);
        for(vector<int> vi : e){
            edges[vi[0]].push_back(vi[1]);
            num_income[vi[1]]++;
        }

        queue<int> q;
        for(int i = 0; i<n; i++){
            if(num_income[i] == 0){
                q.push(i);
            }
        }

        bool hasCycle = false;
        vector<vector<int>> num_color(n, vector<int>(26, 0)); // num_color[v][c] : vertex v까지 탐색했을 때 color c가 나온 회수
        int answer = -1;
        for(int i = 0; i<n; i++){
            if(q.empty()){
                return -1;
            }

            int front = q.front(); q.pop();
            num_color[front][colors[front] - 'a']++;
            answer = max(answer, num_color[front][colors[front] - 'a']);
            
            for(int adj : edges[front]){
                num_income[adj]--;
                if(num_income[adj] == 0) q.push(adj);

                for(int i = 0; i<26; i++){
                    num_color[adj][i] = max(num_color[front][i], num_color[adj][i]);
                }
            }
        }

        return answer;
    }
};

/*
1. cycle 검증
2. 지금까지 + 미래의 모든 color에 대한 값을 가져야 함
BFS?
3. path : cycle이 없고, 마지막에는 outgoing이 없어야 함
DFS?

topological sort?
*/
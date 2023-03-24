// Runtime 342 ms Beats 93.65%
// Memory 106.6 MB Beats 74.70%

struct edge{
    int next;
    bool isOutgoing;
};

class Solution {
public:
    int answer;
    vector<vector<edge>> edges; // edges[i] : ith vertex가 가리키는 {vertex, 나가는지 여부} vector
    vector<bool> visited;
    void DFS(int cur){
        for(edge e : edges[cur]){
            if(!visited[e.next]){
                visited[e.next] = true;
                if(e.isOutgoing) answer++; // 나가는 edge인 경우 뒤집어 주어야 함
                DFS(e.next);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // init
        answer = 0;
        edges.resize(n);
        for(vector<int> &connection : connections){
            edges[connection[0]].push_back({connection[1], true});
            edges[connection[1]].push_back({connection[0], false});
        }
        visited.resize(n);
        fill(visited.begin(), visited.end(), false);

        visited[0] = true;
        DFS(0);

        return answer;
    }
};
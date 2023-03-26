// Runtime 294 ms Beats 56.14%
// Memory 139.1 MB Beats 48.90%

class Solution {
public:
    vector<int> edges;
    vector<bool> visited;
    int answer = 0;
    void DFS(int v, vector<int>& log){ // 일반적 DFS에 방문 기록을 추가
        int w = edges[v];
        if(w == -1) return;
        if(!visited[w]){ // 1번. not visited, then keep traverse
            log.push_back(w);
            visited[w] = true;
            DFS(w, log);
        }
        else{ // 2번. if visited, then stop traverse, find w in traverse log
            int cycleidx = log.size();
            for(int i = 0; i<log.size(); i++){
                if(log[i] == w){
                    cycleidx = i;
                    break;
                }
            }
            answer = max(answer, (int)log.size() - cycleidx);
            return;
        }
    }
    
    int longestCycle(vector<int>& E) {
        edges = E;
        visited.resize(E.size());
        fill(visited.begin(), visited.end(), false);

        for(int i = 0; i<edges.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                vector<int> log = {i};
                DFS(i, log);
            }
        }
        return answer == 0 ? -1 : answer;
    }
};
// Runtime 564 ms Beats 82.93%
// Memory 185.2 MB Beats 59.15%

typedef long long ll;

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> edges;
    int DFS(int v){
        int num = 1;
        for(int w : edges[v]){
            if(!visited[w]){
                visited[w] = true;
                num += DFS(w);
            }
        }
        return num;
    }
    long long countPairs(int n, vector<vector<int>>& adjacents) {
        // init
        visited.resize(n);
        fill(visited.begin(), visited.end(), false);
        edges.resize(n);
        for(vector<int>& adjacent : adjacents){
            edges[adjacent[0]].push_back(adjacent[1]);
            edges[adjacent[1]].push_back(adjacent[0]);
        }

        vector<int> counts; // counts : disjoint set의 vertex 개수 vector
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                visited[i] = true;
                counts.push_back(DFS(i));
            }
        }

        // psum 쓰면 될 것 같은데.
        int csize = counts.size();
        vector<ll> psum(csize, 0); // psum[i] : 0부터 i까지 sum
        psum[0] = counts[0];
        for(int i = 1; i<csize; i++){
            psum[i] = (ll)counts[i] + (ll)psum[i-1];
        }

        // psum[i] - psum[j] : j+1 ~ i까지 sum
        ll answer = 0;
        for(int i = 0; i<csize-1; i++){
            answer += (ll)(psum[csize-1] - psum[i]) * (ll)counts[i];
        }
        return answer;
    }
};

// Runtime 532 ms Beats 92.53%
// Memory 184.1 MB Beats 61.89%

// Runtime 564 ms Beats 82.93%
// Memory 185.2 MB Beats 59.15%


class Solution2 {
public:
    long long countPairs(int n, vector<vector<int>>& adjacents) {
        // ...

        ll sum = 0, answer = 0;
        for(int count : counts){
            sum += (ll) count;
        }

        for(int i = 0; i<counts.size(); i++){
            sum -= (ll)counts[i];
            answer += (ll)counts[i] * sum;
        }
        return answer;
    }
};
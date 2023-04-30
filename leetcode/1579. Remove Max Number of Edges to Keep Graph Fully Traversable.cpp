// Runtime 717 ms Beats 39.49%
// Memory 139 MB Beats 82.61%

class DSU{
public:
    vector<int> rank, parent;
    DSU(int n){
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void join(int x, int y){
        int rx = find(x), ry = find(y);
        if(rank[rx] > rank[ry]){ // ry가 아래로 들어가야 함
            parent[ry] = rx;
        }
        else{
            parent[rx] = ry;
            if(rank[rx] == rank[ry]) rank[ry]++;
        }
    }

    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
};

bool cmp(vector<int>& a, vector<int>& b){
    return a[0] > b[0];
}

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU groupA = DSU(n+1), groupB = DSU(n+1);
        sort(edges.begin(), edges.end(), cmp);
        int answer = 0, numAEdges = 0, numBEdges = 0;
        for(vector<int>& edge : edges){
            int type = edge[0], x = edge[1], y = edge[2];
            bool isAConnected = groupA.isConnected(x, y), isBConnected = groupB.isConnected(x, y);

            if(type == 3){
                if(isAConnected && isBConnected){
                    answer++;
                }
                if(!isAConnected){
                    numAEdges++;
                    groupA.join(x, y);
                }
                if(!isBConnected){
                    numBEdges++;
                    groupB.join(x, y);
                }
            }
            else if(type == 1){
                if(isAConnected) answer++;
                else numAEdges++;
                groupA.join(x, y);
            }
            else if(type == 2){
                if(isBConnected) answer++;
                else numBEdges++;
                groupB.join(x, y);
            }
        }

        if(numAEdges != n-1 || numBEdges != n-1) return -1;        
        return answer;
    }
};

/*
union-find 2개 써야 할 것 같은데.
A, B로 일단 가능한 한 전부 다 넣고
모든 common edge들에 대해 A도, B도 이미 이어져 있는 상태면 지울 수 있음. - 필요 없음.
둘 중 하나라도 이어져 있지 않다면 - 무조건 사용해야 함.
*/
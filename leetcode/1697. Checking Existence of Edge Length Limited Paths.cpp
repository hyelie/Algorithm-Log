// Runtime 652 ms Beats 48.55%
// Memory 110.1 MB Beats 78.84%

bool cmp(vector<int>& a, vector<int>& b){
    if(a[2] < b[2]) return true;
    else return false;
}

class Solution {
public:
    vector<int> parent, rank;
    void makeDS(int n){
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        rank.resize(n, 0);
    }

    int find(int x){
        if(x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void join(int x, int y){
        int rx = find(x), ry = find(y);

        if(rank[rx] > rank[ry]){ // ry가 rx 아래로 들어감
            parent[ry] = rx;
        }
        else{
            if(rank[rx] == rank[ry]){
                rank[ry]++;
            }
            parent[rx] = ry;
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i = 0; i<queries.size(); i++){
            queries[i].push_back(i); // index 추가
        }

        // limit 오름차순 정렬
        sort(queries.begin(), queries.end(), cmp);
        sort(edgeList.begin(), edgeList.end(), cmp);

        makeDS(n);
        int i = 0;
        vector<bool> answer(queries.size(), false);
        for(vector<int>& query : queries){
            int limit = query[2], originIdx = query[3];
            for(; i < edgeList.size() && edgeList[i][2] < limit; i++) join(edgeList[i][0], edgeList[i][1]);

            int x = query[0], y = query[1];
            if(find(x) == find(y)) answer[originIdx] = true;
        }
        
        return answer;
    }
};
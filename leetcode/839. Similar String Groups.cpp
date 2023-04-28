// Runtime 173 ms Beats 48.57%
// Memory 10.6 MB Beats 49.21%

class Solution {
public:
    vector<int> parents;
    vector<int> ranks;
    int sz;
    void makeDS(int size){
        parents.resize(size);
        for(int i = 0; i<size; i++) parents[i] = i;
        ranks.resize(size, 0);
    }

    int find(int v){
        if(v == parents[v]) return v;
        parents[v] = find(parents[v]);
        return parents[v];
    }

    void join(int x, int y){
        int rx = find(x), ry = find(y);
        if(ranks[rx] > ranks[ry]){ // ry가 rx 아래에 들어감
            parents[ry] = rx;
        }
        else{
            if(ranks[rx] == ranks[ry]){
                ranks[ry]++;
            }
            parents[rx] = ry;
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int len = strs.size();
        makeDS(len); // *** 실수 : disjoint set 초기화를 하지 않았음.

        for(int i = 0; i<len; i++){
            for(int j = i+1; j<len; j++){
                if(isSimilar(strs[i], strs[j])){
                    join(i, j);
                }
            }
        }

        set<int> answer;
        for(int i = 0; i<len; i++){ // *** 실수 : find(i)를 결과에 넣어야 하는데 parents[i]를 넣음.
            answer.insert(find(i));
        }
        return answer.size();
    }

    bool isSimilar(string &s1, string &s2){
        int diffCnt = 0, len = s1.length();
        for(int i = 0; i<len; i++){
            if(s1[i] != s2[i]) diffCnt++;
        }
        return diffCnt <= 2;
    }
};
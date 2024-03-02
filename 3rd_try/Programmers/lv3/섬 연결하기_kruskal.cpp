#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int parents[101];
int ranks[101];

void Make_Set(int v){
    parents[v] = v;
    ranks[v] = 0;
}

int Find(int x){
    if(parents[x] == x) return x;
    
    parents[x] = Find(parents[x]);
    return parents[x];
}

void Union(int x, int y){
    int rx = Find(x), ry = Find(y);
    
    if(rx == ry) return;
    
    if(ranks[rx] < ranks[ry]){ // rx가 ry 아래로
        parents[rx] = ry;
    }
    else{ // ry가 rx 아래로, 같은 경우 rx rank ++
        parents[ry] = rx;
        if(ranks[rx] == ranks[ry]) ranks[rx]++;
    }
}

bool cmp(const vector<int>& a, const vector<int> &b) {
    if(a[2] == b[2]){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i<n; i++) Make_Set(i);
    
    int answer = 0;
    for(vector<int> &cost : costs){
        int from = cost[0], to = cost[1], weight = cost[2];
        
        if(Find(from) != Find(to)){
            Union(from, to);
            answer += weight;
        }
    }
    
    return answer;
}

/*
union-find
prim, kruskal
둘 다로 한 번?
*/
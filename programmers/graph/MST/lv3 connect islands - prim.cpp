// 섬 연결하기

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

struct pqcmp{
    bool operator()(pii &a, pii &b){
        return a.second > b.second;
    }
};

int solution(int n, vector<vector<int>> costs) {
    // 초기화 단계
    vector<vector<pii>> adjacent(n);
    for(vi v : costs){
        adjacent[v[0]].push_back({v[1], v[2]});
        adjacent[v[1]].push_back({v[0], v[2]});
    }
    
    int cost = 0;
    set<int> s; s.insert(0);
    priority_queue<pii, vector<pii>, pqcmp> pq; // pii.first : 도착 섬, pii.second : 다리 비용
    for(pii p : adjacent[0]){
        pq.push(p);
    }
    while(s.size() < n){
        pii p = pq.top(); pq.pop();
        if(s.find(p.first) == s.end()){ // 연결되지 않았다면 연결
            s.insert(p.first);
            cost += p.second;
            for(pii next_bridge : adjacent[p.first]) pq.push(next_bridge);
        }
    }
    
    return cost;
}
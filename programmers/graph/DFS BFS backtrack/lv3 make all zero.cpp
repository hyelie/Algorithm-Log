// 모두 0으로 만들기

#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

ll cnt = 0;

void DFS(int cur_node, vector<ll>& weight, vector<bool>& visited, vector<vector<int>> &adjacent){
    visited[cur_node] = true;
    for(int c : adjacent[cur_node]){
        if(!visited[c]){
            visited[c] = true;
            DFS(c, weight, visited, adjacent);
            cnt += abs(weight[c]);
            weight[cur_node] += weight[c];
            weight[c] = 0;
        }
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    ll sum = accumulate(a.begin(), a.end(), 0L);
    if(sum != 0) return -1;
    
    vector<vector<int>> adjacent(a.size());
    for(vector<int> edge : edges){
        adjacent[edge[0]].push_back(edge[1]);
        adjacent[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(a.size(), false);
    vector<ll> weight(a.begin(), a.end());
    
    DFS(0, weight, visited, adjacent);
    return weight[0] == 0 ? cnt : -1;
}

// edge가 1개인 것들만 탐색해서 갱신해 나가면 될 것 같은데
//
#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <cmath>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, ll> pil;

////////////////////// write your code below

struct cmp{
    bool operator()(pil &a, pil&b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

void solve(){
	int V, E; cin>>V>>E;
    vector<vector<pil>> edges(V+1); // .first : vertex, .second : weight

    int from, to; ll weight;
    for(int i = 0; i<E; i++){
        cin>>from>>to>>weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    set<int> mst;
    priority_queue<pil, vector<pil>, cmp> pq;
    ll answer = 0;

    pq.push({1, 0});

    while(mst.size() != V){
        pil top = pq.top(); pq.pop();
        if(mst.find(top.first) == mst.end()){
            answer += top.second;
            mst.insert(top.first);
            for(pil adj : edges[top.first]){
                pq.push(adj);
            }
        }
    }
    cout<<answer;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}
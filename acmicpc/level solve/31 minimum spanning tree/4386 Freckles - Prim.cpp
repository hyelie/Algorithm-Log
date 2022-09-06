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
typedef pair<int, double> pid;
typedef pair<double, double> pdd;

////////////////////// write your code below

struct cmp{
    bool operator()(pid &a, pid&b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

double dist(pdd &a, pdd &b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void solve(){
	int N; cin>>N;
    vector<vector<pid>> edges(N+1); // .first : vertex, .second : weight

    vector<pdd> stars(N);
    for(int i = 0; i<N; i++){
        cin>>stars[i].first>>stars[i].second;
        for(int j = 0; j<i; j++){
            double weight = dist(stars[i], stars[j]);
            edges[i].push_back({j, weight});
            edges[j].push_back({i, weight});
        }
    }

    set<int> mst;
    priority_queue<pid, vector<pid>, cmp> pq;
    double answer = 0;

    pq.push({1, 0});

    while(mst.size() != N){
        pid top = pq.top(); pq.pop();
        if(mst.find(top.first) == mst.end()){
            answer += top.second;
            mst.insert(top.first);
            for(pid adj : edges[top.first]){
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
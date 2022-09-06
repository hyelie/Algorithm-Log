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

struct edge{
    int from, to;
    ll weight;
};
bool cmp(edge &a, edge &b){
    return a.weight < b.weight;
}

int Parent[10001], Rank[10001];

int Find(int v){
    if(v == Parent[v]) return v;
    Parent[v] = Find(Parent[v]);
    return Parent[v];
}

void Union(int x, int y){
    int rx = Find(x), ry = Find(y);
    if(rx == ry) return;
    if(Rank[rx] < Rank[ry]){
        Parent[rx] = ry;
    }
    else{
        Parent[ry] = rx;
        if(Rank[rx] == Rank[ry]){
            Rank[rx]++;
        }
    }
}

void solve(){
	int V, E; cin>>V>>E;
    vector<edge> edges;

    for(int i = 0; i<=V; i++){
        Parent[i] = i;
        Rank[i] = i;
    }

    int from, to; ll weight;
    for(int i = 0; i<E; i++){
        cin>>from>>to>>weight;
        edges.push_back({from, to, weight});
    }
    sort(edges.begin(), edges.end(), cmp);

    ll answer = 0;
    for(edge e : edges){
        if(Find(e.from) != Find(e.to)){
            answer += e.weight;
            Union(e.from, e.to);
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
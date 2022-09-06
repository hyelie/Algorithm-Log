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

struct edge{
    int from, to;
    double weight;
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

double dist(pdd &a, pdd &b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void solve(){
	int N; cin>>N;
    vector<edge> edges;

    for(int i = 0; i<=N; i++){
        Parent[i] = i;
        Rank[i] = i;
    }

    vector<pdd> stars(N);
    for(int i = 0; i<N; i++){
        cin>>stars[i].first>>stars[i].second;
        for(int j = 0; j<i; j++){
            double weight = dist(stars[i], stars[j]);
            edges.push_back({i, j, weight});
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    double answer = 0;
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
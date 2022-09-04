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

////////////////////// write your code below

int Parent[1000001], Rank[1000001];
// parent[i] : vertex i의 parent node
// rank[i] : vertex i의 depth

void Makeset(int v){
	Parent[v] = v;
	Rank[v] = 0;
}

int Find(int v){
	if(v == Parent[v]) return v;
	Parent[v] = Find(Parent[v]); // path compression
	return Parent[v];
}

void Union(int x, int y){
	int root_x = Find(x);
	int root_y = Find(y);

	if(root_x == root_y) return; // in same tree

	if(Rank[root_x] > Rank[root_y]){
		Parent[root_y] = root_x;
	}
	else{ // x가 아래 들어가야 하는 경우
		Parent[root_x] = root_y;
		if(Rank[root_x] == Rank[root_y]){
			Rank[root_x]++;
		}
	}
}

int n, m;
string yes = "YES\n", no = "NO\n";

void solve(){
	cin>>n>>m;

	for(int i = 0; i<=n; i++) Makeset(i);

	int type, a, b;
	while(m--){
		cin>>type>>a>>b;
		if(type == 0){
			Union(a, b);
		}
		else{
			if(Find(a) == Find(b)){
				cout<<yes;
			}
			else cout<<no;
		}
	}


}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}
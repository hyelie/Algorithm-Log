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

int Parent[201], Rank[201];

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

	if(Rank[root_x] < Rank[root_y]){
		Parent[root_x] = root_y;
	}
	else{
		if(Rank[root_x] == Rank[root_y]){
			Rank[root_y]++;
		}
		Parent[root_y] = root_x;
	}
}

int N, M;
void solve(){
	cin>>N>>M;
	for(int i = 0; i<=N; i++) Makeset(i);
	
	int input;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cin>>input;
			if(input == 1){
				Union(i, j);
			}
		}
	}

	cin>>input;
	int root = Find(input);
	string result = "YES";
	for(int i = 1; i<M; i++){
		cin>>input;
		if(root != Find(input)){
			result = "NO";
			break;
		}
	}
	cout<<result;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}
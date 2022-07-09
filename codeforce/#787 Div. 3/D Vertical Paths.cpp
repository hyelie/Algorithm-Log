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
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

bool cmp(pii &a, pii &b){
	if(a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

// height 찾는 게 잘못되었었음.
int getHeight(vector<int>& parent, int n, vector<pii> &height, int cur_num){
	if(height[cur_num].second != -1) return height[cur_num].second;
	if(parent[cur_num] == cur_num) return 0;

	else return getHeight(parent, n, height, parent[cur_num]) + 1;
}

void solve(){
	int n; cin>>n;
	vector<int> parent(n+1);
	for(int i = 1; i<=n; i++) cin>>parent[i];

	vector<pii> height(n+1, {-1, -1}); // .first : number, .second : height
	for(int i = 1; i<=n; i++){
		height[i] = {i, getHeight(parent, n, height, i)};
	}

	sort(height.begin(), height.end(), cmp);
	// after sort, starts with deepest node

	vector<bool> visited(n+1, false);
	vector<vector<int>> paths;

	// print from deepest node to it's root node
	for(int i = 0; i<n; i++){
		int cur_num = height[i].first;
		vector<int> path;
		while(!visited[cur_num]){ // go to unvisited parent node
			path.push_back(cur_num);
			visited[cur_num] = true;
			cur_num = parent[cur_num];
		}
		if(path.size() != 0) paths.push_back(path);
	}

	cout<<paths.size()<<'\n';
	for(vector<int>& vi : paths){
		cout<<vi.size()<<'\n';
		for(auto it = vi.rbegin(); it != vi.rend(); it++){
			cout<<*it<<' ';
		}cout<<'\n';
	}
}

// root부터 dfs를 하던가, 
// deepest leaf부터 visit 표시 하면서 root로 올라오던가. - 이 방식 했음.

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	for(int i = 0; i<t; i++){
		solve();
		cout<<'\n';
	}

	//////////////////////

	return 0;
}
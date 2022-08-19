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

map<pii, int> edge_idx_map;
int n;
set<string> answer;
vector<vector<int>> edges, boards;
vector<bool> visited;
int num_vertex;

/*
점 v에 인접한 사각형
row : v / (n+1) -1, v / (n+1)
col : v % (n+1) -1, v % (n+1)
*/
set<pii> pointAdjacentRectangle(int v){
	int rr = v / (n+1), cc = v % (n+1);
	set<pii> result;
	if(rr < n && cc < n) result.insert({rr, cc});
	if(rr - 1 >= 0 && cc < n) result.insert({rr-1, cc});
	if(cc - 1 >= 0 && rr < n)	result.insert({rr, cc-1});
	if(rr -1 >= 0 && cc - 1 >= 0) result.insert({rr-1, cc-1});

	return result;
}

/*
edge [from, to]에 인접한 사각형
from에 인접한 사각형 + to에 인접한 사각형의 intersect
*/
set<pii> edgeAdjacentRectangle(int from, int to){
	set<pii> adjacent_from = pointAdjacentRectangle(from);
	set<pii> adjacent_to = pointAdjacentRectangle(to);
	set<pii> result;
	for(pii elem : adjacent_from){
		if(adjacent_to.find(elem) != adjacent_to.end()){
			result.insert(elem);
		}
	}
	return result;
}

void mapEdgeToIndex(){
	int cnt = 0;
	for(int i = 0; i<num_vertex; i++){
		if(i % (n+1) == n) continue;
		edge_idx_map[{i, i+1}] = edge_idx_map[{i+1, i}] = cnt;
        edges[i].push_back(i+1);
        edges[i+1].push_back(i);
		cnt++;
	}

	for(int i = 0; i<num_vertex; i++){
		if(i / (n+1) == n) continue;
		edge_idx_map[{i, i+n+1}] = edge_idx_map[{i+n+1, i}] = cnt;
        edges[i].push_back(i+n+1);
        edges[i+n+1].push_back(i);
		cnt++;
	}
}

bool putable(int from, int to){
	set<pii> adjRecs = edgeAdjacentRectangle(from, to);
	for(pii elem : adjRecs){
		if(boards[elem.first][elem.second] == 0){
			return false;
		}
	}
	return true;
}

void dfs(bool isinit, int start_vertex, int cur, string str){
	if(isinit == false && start_vertex == cur){
		for(int i = 0; i<n; i++){
			for(int j = 0;j<n;j++){
				if(boards[i][j] > 0) return;
			}
		}
		answer.insert(str);
		return;
	}

	isinit = false;
	for(int adj : edges[cur]){
		if(!visited[adj]){
			set<pii> adjRecs = edgeAdjacentRectangle(cur, adj);
			for(pii elem : adjRecs){
				boards[elem.first][elem.second]--;
			}
			visited[adj] = true;
			str[edge_idx_map[{cur, adj}]] = '1';
			dfs(isinit, start_vertex, adj, str);
			for(pii elem : adjRecs){
				boards[elem.first][elem.second]++;
			}
			visited[adj] = false;
			str[edge_idx_map[{cur, adj}]] = '0';
		}
	}
}

int solution(vector<vector<int>> board) {
	boards = board;
    n = board.size();
	num_vertex = (n+1) * (n+1);
    edges.resize(num_vertex);
	visited.resize(num_vertex);
	fill(visited.begin(), visited.end(), false);
    mapEdgeToIndex();

    string empty_str = "";
    for(int i = 0; i<2 * n * (n+1); i++){
        empty_str += "0";
    }

	for(int i = 0; i<num_vertex; i++){
		visited[i] = true;
		dfs(true, i, i, empty_str);
		visited[i] = false;
	}

    return answer.size();
}

void solve(){
	vector<vector<int>> board = {
		{2, -1},
		{-1, 2}
	};
	cout<<solution(board);
}

/*
	이렇게 줄세웠을 때 (r, c)번째 사각형 주변에 있는 직선
		c%n
	r%n			r%n+1
		c%n + n
*/

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}
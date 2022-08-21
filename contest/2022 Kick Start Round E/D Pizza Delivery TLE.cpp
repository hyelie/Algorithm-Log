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
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<int, string> pis;

////////////////////// write your code below

int N, P, M, AR, AC; 
// N : grid size, P : # of pizza, M : minutes, AR, AC : starting coordinate 

pci OP[4];
map<pii, int> customers; // customer info. customers[pii] : coins
map<pii, bool> visited; // 손님 i를 방문했는지
int INF = 987654321;
int max_coin = -1;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, 1, -1, 0};
// 위, 오, 왼, 아

// 갈 때 소지금 origin과 op를 했을 때 결과 리턴
int operate(int origin, pci op){
	if(op.first == '+'){
		return origin + op.second;
	}
	if(op.first == '-'){
		return origin - op.second;
	}
	if(op.first == '*'){
		return origin * op.second;
	}
	if(op.first == '/'){
		return origin / op.second;
	}
}

/*bool isAllDelivered(){
	for(auto i = visited.begin(); i != visited.end(); i++){
		if(i->second == false){
			return false;
		}
	}
	return true;
}*/

void dfs(int cur_depth, int cur_coin, pii cur_p){
	if(cur_depth == M){
		/*if(isAllDelivered()){
			max_coin = max(max_coin, cur_coin);
		}*/
		max_coin = max(max_coin, cur_coin);
		return;
	}

	int cr = cur_p.first, cc = cur_p.second; // current r, current c
	// bool existCustomer = (customers.find(cur_p) != customers.end()); // 있으면 true
	// cout<<"현재위치 : "<<cr<<", "<<cc<<endl;
	for(int d = 0; d<4; d++){
		int nr = cr + dr[d];
		int nc = cc + dc[d];
		
		if(1 <= nr && nr <= N && 1 <= nc && nc <= N){
			/*if(existCustomer){ // 있으면 할 수 있음
				visited[cur_p] = true;
				int next_coin = cur_coin + customers[cur_p];
				next_coin = operate(next_coin, OP[d]);
				dfs(cur_depth+1, next_coin, {nr, nc});
				visited[cur_p] = false;
			}*/

			// 다음 위치 가기
			int next_coin = operate(cur_coin, OP[d]);
			dfs(cur_depth+1, next_coin, {nr, nc});
		}
	}
	// 아무것도 안하기
	dfs(cur_depth+1, cur_coin, cur_p);
}

void solve(){
	cin>>N>>P>>M>>AR>>AC;
	for(int i = 0; i<4; i++){
		cin>>OP[i].first >> OP[i].second;
	}
	for(int i = 0; i<P; i++){
		int icr, icc, iccoin;
		cin>>icr>>icc>>iccoin;
		customers[{icr, icc}] = iccoin;
		visited[{icr, icc}] = false;
	}

	dfs(0, 0, {AR, AC});
}

/*
[AR, AC]에서 소지금 0으로 시작함. 모든 피자를 M분 안에 배달 목표, 코인 최대화
길은 어디로 가든 상관 X, edge 하나 쓰면 1분 걸림
grid 밖으로 못나감, 움직이지 않을 수 있음, 배달 안해도 됨.
toll system이 있음, [위, 오, 왼, 아] 순서로 주어지며, 이건 구현했음

DFS인데... '특정 위치 방문' + 'maximize'가 합쳐진...
*/

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	for(int i =1; i<=t; i++){
		max_coin = -1;
		solve();
		cout<<"Case #"<<i<<": "<<max_coin<<'\n';
	}

	return 0;
}

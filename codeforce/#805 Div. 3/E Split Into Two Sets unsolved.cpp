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

string no = "NO\n", yes = "YES\n";

bool insertable(pii& domino, vector<bool>& isUsed){
	if(domino.first == domino.second) return false;
	else if(!isUsed[domino.first] && !isUsed[domino.second]) return true;
	else return false;
}

void solve(){
	int n; cin>>n; // 짝수
	vector<pii> dominos(n); // 1~n까지 수를 포함함
	for(pii &domino : dominos){
		cin>>domino.first>>domino.second;
		domino.first--; domino.second--;
	}

	// 한쪽에 최대한 넣을 수 있을 만큼 넣고
	vector<bool> isUsedA(n, false), isUsedB(n, false);
	for(pii &domino : dominos){
		if(insertable(domino, isUsedA)){
			isUsedA[domino.first] = isUsedA[domino.second] = true;
		}
		else if(insertable(domino, isUsedB)){
			isUsedB[domino.first] = isUsedB[domino.second] = true;
		}
		else{
			cout<<no;
			return;
		}
	}
	cout<<yes;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
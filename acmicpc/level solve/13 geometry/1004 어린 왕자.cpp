#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int getDistPower(int x1, int y1, int x2, int y2){
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve(){
	int x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;

	int n; cin>>n;
	int cx, cy, r;
	int num_sp = 0, num_dest = 0, num_both = 0;
	while(n--){
		cin>>cx>>cy>>r;
		bool isContainStart = getDistPower(x1, y1, cx, cy) <= r * r;
		bool isContainDest = getDistPower(x2, y2, cx, cy) <= r * r;
		if(isContainStart) num_sp++;
		if(isContainDest) num_dest++;
		if(isContainStart && isContainDest){
			num_both++;
		}
	}
	
	cout<<num_sp + num_dest - 2* num_both<<'\n';
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int T; cin>>T;
	while(T--){
		solve();
	}

	//////////////////////

	return 0;
}

/*
출발점을 포함하는 원 + 도착점을 포함하는 원 - 출발점+도착점을 포함하는 원의 개수
가 답
*/
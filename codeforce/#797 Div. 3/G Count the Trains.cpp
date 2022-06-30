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

void solve(){
	int n, m; cin>>n>>m;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin>>a[i];
	set<int> carriage;
	for(int i = 0; i<n; i++){
		carriage.insert(a[i]);
		while(i+1 < n && a[i] < a[i+1]){
			i++;
		}
	}

	for(int i : carriage) cout<<i<<'\n';

	int k, d;
	while(m--){
		cin>>k>>d;
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}

/*
각각 k, d에 대해 줄이고, 줄인 이후에 몇 개의 군집이 남아있는지 계산하는 문제임

어떤 수가 줄면, 그 수부터 끝까지 upper bound(그 수보다 크거나 같은 제일 작은 수)를 찾아서
바뀐 수부터 그 수의 upper bound까지 전부 바뀐 수로 바뀌어야 함

숫자들의 set을 보관한다면, 그 set size가 답임.

O(m nlogn)
*/
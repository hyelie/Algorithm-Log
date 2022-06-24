#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

void solve(){
	int n, k; cin>>n>>k;
	vector<int> arr(n);
	for(int i = 0;i <n; i++){
		cin>>arr[i];
	}

	vector<int> v(n); v[0] = 0;
	int flag;
	for(int i = 1; i<n; i++){
		flag = 0;
		if(arr[i] > arr[i-1] / 2) flag = 1;
		v[i] = flag;
	}
	
	int answer = 0, cur_point = 0;
	for(int i = 0; i<k; i++){
		cur_point += v[i];
	}
	if(cur_point == k) answer++;

	for(int i = k; i<n; i++){
		cur_point += v[i] - v[i-k];
		if(cur_point == k) answer++;
	}
	cout<<answer<<'\n';
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}

/*
arr[i] < 2 * arr[i+1]이 가능하다면 'true - 해당 array는 포함될 수 있음' 표시
20 22 19 84
1 1 1 1

k = 2
9 5 3 2 1
1 1 1 1 0

7 3
22 12 16 4 3 22 12
4 3 22 12

1 1 1 0 1 1 1

sliding window인 듯!

01111....11이거나
1111...111이거나

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

void solve(){
	int n; cin>>n;

	int input;
	map<int, int> m; // key : 숫자, value : 그 수의 개수
	for(int i = 0; i<n; i++){
		cin>>input;
		m[input]++;
	}

	int num_num = m.size(), remove_num = n-num_num;
	if(remove_num&1) remove_num++;
	cout<<n-remove_num<<'\n';
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

void solve(){
	int a;
	vector<int> others(3);
	cin>>a>>others[0]>>others[1]>>others[2];

	int answer = 0;
	for(int i = 0; i<3; i++){
		if(a < others[i]){
			answer++;
		}
	}
	cout<<answer<<'\n';
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
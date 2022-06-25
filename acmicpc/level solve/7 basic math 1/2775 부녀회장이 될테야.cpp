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
void solve(){
	int k, n;

	cin>>k>>n;
	vector<int> num_people(n+1);
	for(int i = 0; i<n+1; i++){
		num_people[i] = i;
	}

	while(k-->0){
		for(int i = 1; i<n+1; i++){
			num_people[i] += num_people[i-1];
		}
	}

	cout<<num_people[n]<<'\n';

	return;
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
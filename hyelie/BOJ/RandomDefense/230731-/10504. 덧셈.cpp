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

vector<ll> sumToI; // sumToI[i] : 1부터 i+1까지 sum

void init(){
	int i = 1;
	ll sum = 0;
	while(1){
		sum = (i+1) * i / 2;
		i++;
		if(sum > 1e9) break;
		sumToI.push_back(sum);
	}
}

void solve(){
	int N; cin>>N;

	for(int i = 0; i<sumToI.size(); i++){
		ll sum = sumToI[i];
		if(N < sum) break;
		if((N - sum) % (i+1) == 0 && i != 0){
			ll gap = (N - sum) / (i+1);
			cout<<N<<" = ";
			for(int n = 1; n<i+1; n++){
				cout<<n+gap<<" + ";
			}
			cout<<i+1+gap<<'\n';
			return;
		}
	}
	cout<<"IMPOSSIBLE\n";
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	init();
	while(t--){
		solve();
	}

	return 0;
}
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
	ll n; cin>>n;
	vector<ll> arr(n);
	ll input;
	for(int i = 0; i<n; i++){
		cin>>arr[n-i-1];
	}

	ll result = 0;
	for(int i = 1; i<n; i++){
		if(arr[i-1] == 0){
			result = -1;
			break;
		}
		while(arr[i-1] <= arr[i]){
			arr[i] /= 2;
			result++;	
		}
	}

	cout<<result<<'\n';

	return;

}

/*
3 6 5 (2 3 3)
3 3 5
1 3 5

5 3 2 1
-1

1 2 3 4 5
0

100000
0

2 8 7 5 (2 4 3 3) -> (0 1 2 3)
2 8 3 5
2 4 3 5
2 2 3 5
1 2 3 5

8 26 5 21 10 (4 5 3 5 4) - (0 1 2 3 4)
8 26 5 10 10
8 26 5 5 10
8 26 2 5 10
13 6 3 1
4 2 1 0
*/

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
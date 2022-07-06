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
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	ll arr[101] = {0, };
	arr[0] = arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;
	for(int i = 6; i<= 100; i++){
		arr[i] = arr[i-1] + arr[i-5];
	}

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		cout<<arr[n]<<'\n';
	}



	//////////////////////

	return 0;
}
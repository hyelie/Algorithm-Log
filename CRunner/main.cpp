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

void solve(){
	int N; cin>>N;
	vector<int> arr(N);
	for(int i = 0; i<N; i++) cin>>arr[i];

	for(int i = 0; i<N; i++) cout<<arr[i];

	return;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();
	
	return 0;
}
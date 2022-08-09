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

void solve(){
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int X, N; cin>>X>>N;
	int a, b;
	while(N--){
		cin>>a>>b;
		X -= (a * b);
	}
	if(X == 0) cout<<"Yes";
	else cout<<"No";

	//////////////////////

	return 0;
}
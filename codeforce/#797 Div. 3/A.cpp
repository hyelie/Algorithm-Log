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
	int n; cin>>n;

	int h1 = (int)ceil((double)(n+3)/3);
	int h2 = (n - h1)/2 + 1;
	int h3 = n - h1 - h2;
	cout<<h2<<' '<<h1<<' '<<h3<<'\n';
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
x + x+1 + x+2 = 3x + 3
(input-3)/3 = x

x x-1 x-2 = 3x-3
(input+3)/3 = x(올림) 이게 h1
(input - x) / 2 + 1 : 2번째,
input - x - 2번째 : 3번째
로 두면 될 것 가틍ㄴ데

*/
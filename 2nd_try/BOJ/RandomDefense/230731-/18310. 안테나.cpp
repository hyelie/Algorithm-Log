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

// N = 20만, 범위는 10만
// BF로는 절대 못풀고, 아마 binary search인 듯.
// BS도 아닌 것 같기도 하고... OX로 표현할 수 있는 게 아님. 기준이 잡혀야 함.


int N;
vector<int> houses;	

void solve(){
	cin>>N;
	houses.resize(N);
	for(int i = 0; i<N; i++){
		cin>>houses[i];
	}	

	// sort
	sort(houses.begin(), houses.end(), less<int>());
	
	// get mid
	int mid = (N-1)/2;

	// get answer
	// ll answer = 0;
	// for(int house : houses){
	// 	answer += (ll)abs(houses[mid] - house);
	// }
	// cout<<answer;
	cout<<houses[mid];

	return;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}
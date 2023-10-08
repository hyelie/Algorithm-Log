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

int solve(){
	int N, M; cin>>N>>M;
	priority_queue<int, vector<int>, less<int>> pq;
	int input;
	for(int i = 0; i<N; i++){
		cin>>input;
		pq.push(input);
	}
	vector<int> wants(M);
	for(int i = 0; i<M; i++) cin>>wants[i];

	for(int want : wants){
		int t = pq.top(); pq.pop();
		if(t < want) return 0;
		t -= want;
		pq.push(t);
	}

	return 1;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	cout<<solve();

	return 0;
}
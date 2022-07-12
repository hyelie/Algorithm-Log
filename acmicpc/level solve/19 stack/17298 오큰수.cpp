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
#include <stack>

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
	
	int N; cin>>N;
	vector<int> arr(N);
	for(int i = 0; i<N; i++) cin>>arr[i];

	stack<pii> s; // .first : value, .second : index
	for(int i = 0; i<N; i++){
		// while s is not empty and s.top's value < arr[i]
		// then s.top()'s NGE is arr[i]
		// so pop from s
		while(!s.empty() && s.top().first < arr[i]){
			arr[s.top().second] = arr[i];
			s.pop();
		}
		// after pop all value less than arr[i]
		// then push arr[i]
		s.push({arr[i], i});
	}
	// and after for loop, remain numbers don't have NGE
	while(!s.empty()){
		arr[s.top().second] = -1;
		s.pop();
	}

	for(int i : arr) cout<<i<<' ';
	//////////////////////

	return 0;
}
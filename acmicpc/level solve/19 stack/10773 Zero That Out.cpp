#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <stack>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int K, input; cin>>K;
	stack<int> s;
	while(K--){
		cin>>input;
		if(input != 0) s.push(input);
		else{
			if(!s.empty()) s.pop();
		}
	}

	ll answer = 0;
	while(!s.empty()){
		answer += (ll)s.top(); s.pop();
	}
	cout<<answer;

	//////////////////////

	return 0;
}
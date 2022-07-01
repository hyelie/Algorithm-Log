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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;
	map<int, pii> m; // key : 속도, value.first : car number, value.second : 내구도
	
	int v, w;
	for(int i = 0; i<n; i++){
		cin>>v>>w;
		if(m.find(v) == m.end()) m[v] = {i+1, w};
		else{
			if(m[v].second <= w){
				m[v].first = i+1;
				m[v].second = w;
			}
		}
	}

	int answer = 0;
	for(auto& [key, value] : m){
		answer += value.first;
	}

	cout<<answer;

	// 같은 속도 -> 내구도 높은 것만 올 수 있음
	// 속도별로 정리하면 되고

	//////////////////////

	return 0;
}
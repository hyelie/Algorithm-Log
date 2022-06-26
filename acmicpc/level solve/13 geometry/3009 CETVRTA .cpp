#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below

	map<int, int> x, y;
	for(int i =0 ;i < 3; i++){
		int xi, yi; cin>>xi>>yi;
		x[xi]++; y[yi]++;
	}

	for(auto [key, value] : x){
		if(value == 1) cout<<key<<' ';
	}
	for(auto [key, value] : y){
		if(value == 1) cout<<key<<' ';
	}

	//////////////////////

	return 0;
}
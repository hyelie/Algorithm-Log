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

bool cmp(const pis &a, const pis &b){

	return a.first < b.first;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	vector<pis> v(N);
	for(int i = 0; i<N; i++){
		cin>>v[i].first>>v[i].second;
	}

	stable_sort(v.begin(), v.end(), cmp);

	for(pis people : v){
		cout<<people.first<<' '<<people.second<<'\n';
	}

	//////////////////////

	return 0;
}
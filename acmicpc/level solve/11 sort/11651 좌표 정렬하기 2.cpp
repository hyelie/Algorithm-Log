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

bool cmp(pii &a, pii &b){
	if(a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	vector<pii> v(N);
	int x, y;
	for(int i = 0; i<N; i++){
		cin>>v[i].first>>v[i].second;
	}

	sort(v.begin(), v.end(), cmp);

	for(pii point : v){
		cout<<point.first<<' '<<point.second<<'\n';
	}

	//////////////////////

	return 0;
}
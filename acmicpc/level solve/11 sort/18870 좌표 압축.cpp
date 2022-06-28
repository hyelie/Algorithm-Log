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
	map<int, int> mapper;
	vector<int> v(N);
	set<int> temp;
	for(int i = 0; i<N; i++){
		cin>>v[i];
		temp.insert(v[i]);
	}

	int i = 0;
	for(int elem : temp){
		mapper[elem] = i++;
	}

	for(int i : v){
		cout<<mapper[i]<<' ';
	}



	//////////////////////

	return 0;
}
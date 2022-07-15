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

ll INF = 200000000000000;
ll answer = -1;

void divide(int i, int j, vector<ll> &rectangles){
	if(i > j || j < i) return;
	if(i == j){
		answer = max(answer, rectangles[i]);
		return;
	}
	// index i to index j까지 min 값을 빠르게 알아와야 하는데.....
	ll min_height = INF, min_height_idx;
	for(int h = i; h<=j; h++){
		if(rectangles[h] < min_height){
			min_height = rectangles[h];
			min_height_idx = h;
		}
	}

	vector<int> min_indexes;
	for(int h = i; h<=j; h++){
		if(rectangles[h] == min_height) min_indexes.push_back(h);
	}
	min_height_idx = min_indexes[(min_indexes.size()-1)/2];

	answer = max(answer, min_height * (j - i + 1));

	divide(i, min_height_idx-1, rectangles);
	divide(min_height_idx+1, j, rectangles);

	return;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n;
	while(1){
		cin>>n;
		if(n == 0) break;
		vector<ll> rectangles(n);
		for(int i = 0; i<n; i++) cin>>rectangles[i];
		answer = -1;
		divide(0, n-1, rectangles);

		cout<<answer<<'\n';
	}

	//////////////////////

	return 0;
}
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
	
	int nr; cin>>nr;
	vector<vector<int>> tri(nr+1, vector<int>(nr+1, 0));
	for(int r = 1; r<=nr; r++){
		for(int c = 1; c<=r; c++){
			cin>>tri[r][c];
		}
	}

	for(int r = 2; r<=nr; r++){
		for(int c = 1; c<=r; c++){
			tri[r][c] += max(tri[r-1][c], tri[r-1][c-1]);
		}
	}

	cout<<*max_element(tri[nr].begin(), tri[nr].end());



	//////////////////////

	return 0;
}
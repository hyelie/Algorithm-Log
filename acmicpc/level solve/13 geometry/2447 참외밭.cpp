#define _USE_MATH_DEFINES 
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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	int unit; cin>>unit;
	int N = 6, direction, length;
	vector<int> xpoints(7), ypoints(7);
	int x = 0, y = 0;
	for(int i = 0; i<N; i++){
		cin >> direction >> length;
		x += dx[direction-1] * length;
		y += dy[direction-1] * length;
		xpoints[i] = x;
		ypoints[i] = y;
	}

	int left = 0, right = 0;
	for(int i = 0; i<N; i++){
		left += xpoints[i] * ypoints[(i+1)%6];
		right += ypoints[i] * xpoints[(i+1)%6];
	}

	cout<<unit * abs(left - right) / 2;
	

	//////////////////////

	return 0;
}

/*
1 1 (목표)

1 2
1 3
3 3
3 1
2 1
2 2

*/
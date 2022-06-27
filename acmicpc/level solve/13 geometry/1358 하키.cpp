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

int getDistPower(int x1, int y1, int x2, int y2){
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int answer = 0;
	int W, H, X, Y, P;
	cin>>W>>H>>X>>Y>>P;
	int r = H/2;
	int x1 = X, y1 = Y + r, x2 = X + W, y2 = Y + r;
	
	int x, y;
	while(P--){
		cin>>x>>y;
		bool left = getDistPower(x1, y1, x, y) <= r * r;
		bool right = getDistPower(x2, y2, x, y) <= r * r;
		bool middle = X <= x && x <= X + W && Y <= y && y <= Y + H;
		if(left || right || middle) answer++;
	}
	cout<<answer;

	//////////////////////

	return 0;
}
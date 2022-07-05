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

int INF = -10000000;
vector<vector<vector<int>>> arr(51, vector<vector<int>>(51, vector<int>(51, INF)));

int solve(int a, int b, int c){
	if(a<=0 || b <= 0 || c <= 0) return 1;
	if(arr[a][b][c] != INF) return arr[a][b][c];

	int value;
	if(a > 20 or b > 20 or c > 20){
		value = solve(20, 20, 20);
	}
	else if(a < b && b < c) {
		value = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
	} 
	else{
		value = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
	}
	arr[a][b][c] = value;
	return value;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int a, b, c;

	while(1){
		cin>>a>>b>>c;
		if(a == -1 && b == -1 && c == -1){
			break;
		}
		string s = "w(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ") = " + to_string(solve(a, b, c));
		cout<<s<<'\n';
	}



	//////////////////////

	return 0;
}
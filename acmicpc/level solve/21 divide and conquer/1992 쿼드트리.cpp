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

string board[64];
string result = "";

void recurse(int r, int c, int length){
	int num_one = 0;
	for(int i = r; i<r + length; i++){
		for(int j = c; j<c+length; j++){
			if(board[i][j] == '1') num_one++;
		}
	}

	if(num_one == 0){
		result += "0";
		return;
	}
	else if(num_one == length * length){
		result += "1";
		return;
	}

	result += "(";
	recurse(r, c, length/2);
	recurse(r, c + length/2, length/2);
	recurse(r + length/2, c, length/2);
	recurse(r + length/2, c + length/2, length/2);
	result += ")";
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	for(int i = 0; i<N; i++) cin>>board[i];

	recurse(0, 0, N);
	cout<<result;

	//////////////////////

	return 0;
}
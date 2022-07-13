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

typedef vector<vector<int>> matrix;
int MOD = 1000;

matrix operator*(const matrix& a, const matrix& b){
	int ar = a.size(), bc = b[0].size(), acbr = b.size();
	matrix result(ar, vector<int>(bc, 0));
	for(int k = 0; k<acbr; k++){
		for(int i = 0; i<ar; i++){
			int temp = a[i][k];
			for(int j = 0; j<bc; j++){
				result[i][j] = (temp * b[k][j] + result[i][j]) % MOD;
			}
		}
	}
	return result;
}


int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; ll B; cin>>N>>B;
	matrix m(N, vector<int>(N)), result(N, vector<int>(N, 0));
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cin>>m[i][j];
			if(i == j) result[i][j] = 1; // identity of matrix
		}
	}
		
	while(B != 0){
		if(B & 1LL){
			result = (result * m);
		}
		m = (m * m);
		B >>= 1;
	}

	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cout<<result[i][j]<<' ';
		}
		cout<<'\n';
	}

	//////////////////////

	return 0;
}
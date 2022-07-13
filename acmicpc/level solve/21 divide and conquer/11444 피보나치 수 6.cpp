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

typedef vector<vector<ll>> matrix;
ll MOD = 1000000007;

matrix operator*(const matrix& a, const matrix& b){
	int ar = a.size(), bc = b[0].size(), acbr = b.size();
	matrix result(ar, vector<ll>(bc, 0));
	for(int k = 0; k<acbr; k++){
		for(int i = 0; i<ar; i++){
			ll temp = a[i][k];
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
	
	
	ll factor; cin>>factor;

	matrix m(2, vector<ll>(2, 1));
	m[1][1] = 0;

	matrix result(2, vector<ll>(2, 0));
	result[0][0] = result[1][1] = 1; // result : identity of matrix
		
	while(factor != 0){
		if(factor & 1LL){
			result = (result * m);
		}
		m = (m * m);
		factor >>= 1;
	}

	cout<<result[0][1];

	//////////////////////

	return 0;
}
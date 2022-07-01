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
	
	int N = 30;
	vector<vector<int>> ptriangle(N+1, vector<int>(N+1, 0));
	for(int i = 0; i<=N; i++){
		ptriangle[i][0] = ptriangle[i][i] = 1;
	}
	// pascal triangle

	for(int i = 2; i<=N; i++){
		for(int k = 1; k<i; k++){
			ptriangle[i][k] = (ptriangle[i-1][k-1] + ptriangle[i-1][k]);
		}
	}

	int t; cin>>t;
	while(t--){
		int n, m; cin>>n>>m;
		cout<<ptriangle[m][n]<<'\n';
	}

	


	//////////////////////

	return 0;
}
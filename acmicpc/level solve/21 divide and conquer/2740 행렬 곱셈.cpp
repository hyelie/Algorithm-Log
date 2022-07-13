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

	int N, M, K;
	cin>>N>>M;
	vector<vector<int>> A(N, vector<int>(M));
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			cin>>A[i][j];
		}
	}

	cin>>M>>K;
	vector<vector<int>> B(M, vector<int>(K));
	for(int i = 0; i<M; i++){
		for(int j = 0; j<K; j++){
			cin>>B[i][j];
		}
	}

	vector<vector<int>> C(N, vector<int>(K, 0));

	// for(int i = 0; i<N; i++){
	// 	for(int j = 0; j<K; j++){
	// 		for(int k = 0; k<M; k++){
	// 			C[i][j] += A[i][k] * B[k][j];
	// 		}
	// 	}
	// }

	for(int k = 0; k<M; k++){
		for(int i = 0; i<N; i++){
			int temp = A[i][k];
			for(int j = 0; j<K; j++){
				C[i][j] += temp * B[k][j];
			}
		}
	}
	

	for(int i = 0; i<N; i++){
		for(int j = 0; j<K; j++){
			cout<<C[i][j]<<' ';
		}
		cout<<'\n';
	}

	//////////////////////

	return 0;
}
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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int M, N; cin>>M>>N;

	int INF = 10000;
	vector<bool> isPrime(INF+1, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i<=sqrt(INF); i++){
		if(isPrime[i]){
			for(int j = i*i; j<=INF; j += i){
				isPrime[j] = false;
			}
		}
	}

	int sum = 0, minval = INF+1;
	for(int n = N; n>=M; n--){
		if(isPrime[n]){
			sum += n;
			minval = n;
		}
	}
	if(sum == 0) cout<<"-1";
	else cout<<sum<<'\n'<<minval;

	return 0;
}
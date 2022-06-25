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

	int INF = 1000000;
	vector<bool> isPrime(INF+1, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i<=sqrt(INF); i++){
		if(isPrime[i]){
			for(int j = i*i; j<=INF; j+=i){
				isPrime[j] = false;
			}
		}
	}

	for(int num = M; num<=N; num++){
		if(isPrime[num]) cout<<num<<'\n';
	}

	return 0;
}
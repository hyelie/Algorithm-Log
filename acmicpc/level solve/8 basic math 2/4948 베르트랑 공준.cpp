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

	

	int INF = 123456 * 2;
	vector<bool> isPrime(INF+1, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i<=sqrt(INF); i++){
		if(isPrime[i]){
			for(int j = i*i; j<=INF; j+=i){
				isPrime[j] = false;
			}
		}
	}

	int N;
	while(1){
		cin>>N;
		if(N == 0) break;
		int cnt = 0;
		for(int num = N+1; num<=2*N; num++){
			if(isPrime[num]) cnt++;
		}
		cout<<cnt<<'\n';
	}
	

	return 0;
}
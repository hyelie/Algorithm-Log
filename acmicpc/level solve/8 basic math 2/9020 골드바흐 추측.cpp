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
int INF = 10000;
bool isPrime[10001] = {true,};
vector<int> primes;

// 2보다 큰 짝수는 두 소수의 합으로 표현할 수 있다.

void solve(){
	int n; cin>>n;

	int a = -1, b = INF+1;

	for(int p : primes){
		if(isPrime[abs(n-p)]){
			if(abs(b-a) > abs(n-2*p)){
				a = p;
				b = abs(n-p);
			}
		}
	}
	cout<<a<<' '<<b<<'\n';
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i<=INF; i++) isPrime[i] = true;
	for(int i = 2; i<=sqrt(INF); i++){
		if(isPrime[i]){
			for(int j = i*i; j<=INF; j+=i){
				isPrime[j] = false;
			}
		}
	}

	for(int i = 2; i<=INF; i++){
		if(isPrime[i]) primes.push_back(i);
	}

	int T; cin>>T;
	while(T--){
		solve();
	}
	

	return 0;
}
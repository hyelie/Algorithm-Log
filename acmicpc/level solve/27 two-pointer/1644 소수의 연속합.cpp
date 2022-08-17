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
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below

int maxn = 4000000;
vector<int> primes;

void sieve(){
	vector<bool> isPrime(maxn+1, true);
	isPrime[0] = isPrime[1] = false;
	for(ll i = 2; i<=maxn; i++){
		if(isPrime[i]){
			primes.push_back(i);
			for(ll j = i*i; j<=maxn; j += i){
				isPrime[j] = false;
			}
		}	
	}
}

void solve(){
	sieve();
	int N; cin>>N;
	int s = 0, e = 0, cur_sum = 0, answer = 0;
	while(e <= primes.size()){
		if(cur_sum <= N){
			if(cur_sum == N) answer++;
			if(e == primes.size()) break;
			cur_sum += primes[e]; e++; 
		}
		else {// cur_sum > N
			
			cur_sum -= primes[s]; s++;
		}
	}
	cout<<answer;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}
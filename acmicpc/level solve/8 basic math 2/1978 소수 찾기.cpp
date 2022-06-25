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
	
	vector<int> isPrime(1001, true);
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i<=sqrt(1000); i++){
		if(isPrime[i]){
			for(int j = i*i; j<=1000; j+=i){
				isPrime[j] = false;
			}
		}
	}

	int input, N, answer = 0; cin>>N;
	while(N--){
		cin>>input;
		if(isPrime[input] == true) answer++;

	}
	cout<<answer;

	return 0;
}
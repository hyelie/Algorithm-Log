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

int gcd(int a, int b){
	if(a < b) return gcd(b, a);
	int r;
	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N, K; cin>>N>>K;
	int result = 1;
	for(int i = N; i>N-K; i--) result *= i;
	for(int i = K; i>=2; i--) result /= i;
	cout<<result;


	//////////////////////

	return 0;
}
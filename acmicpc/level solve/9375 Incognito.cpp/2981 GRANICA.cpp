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
	int r = a%b;
	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	vector<int> v(N);
	for(int i = 0; i<N; i++) cin>>v[i];

	int result = abs(v[0] - v[1]);
	for(int i = 2; i<N; i++){
		result = gcd(result, abs(v[i] - v[i-1]));
	}

	vector<int> answer;
	for(int i = 2; i<=sqrt(result); i++){
		if(result % i == 0){
			answer.push_back(i);
			if(result / i != i) answer.push_back(result/i);
		}
	}
	answer.push_back(result);

	sort(answer.begin(), answer.end());

	for(int i : answer) cout<<i<<'\n';
	
	//////////////////////

	return 0;
}
/*
N개의 수가 주어지고, 1보다 큰 M에 대해 
N%M이 모두 같은 수가 되는 모든 M
*/
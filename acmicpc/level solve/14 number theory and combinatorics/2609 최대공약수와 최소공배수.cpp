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
	
	int a, b; cin>>a>>b;
	cout<<gcd(a, b)<<'\n';
	cout<<lcm(a, b)<<'\n';
	//////////////////////

	return 0;
}
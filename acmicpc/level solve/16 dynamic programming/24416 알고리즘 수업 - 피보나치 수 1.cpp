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

int num_recurse = 0, num_dp = 0;

int recurse(int n){
	if(n == 1 || n == 2){
		num_recurse++;
		return 1;
	}
	return recurse(n-1) + recurse(n-2);
}

int arr[41];
int dp(int n){
	arr[1] = arr[2] = 1;
	for(int i = 3; i<=n; i++){
		arr[i] = arr[i-2] + arr[i-1];
		num_dp++;
	}
	return arr[n];
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;
	recurse(n);
	dp(n);
	cout<<num_recurse<<' '<<num_dp;



	//////////////////////

	return 0;
}
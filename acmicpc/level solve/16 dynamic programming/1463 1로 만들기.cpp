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

int INF = -1;
vector<int> arr(1000001, INF);

int solve(int n){
	if(arr[n] != INF) return arr[n];

	arr[n] = solve(n-1) + 1;
	if(n%2 == 0) arr[n] = min(arr[n], solve(n/2) + 1);
	if(n%3 == 0) arr[n] = min(arr[n], solve(n/3) + 1);

	return arr[n];
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;
	arr[1] = 0;
	cout<<solve(n);



	//////////////////////

	return 0;
}
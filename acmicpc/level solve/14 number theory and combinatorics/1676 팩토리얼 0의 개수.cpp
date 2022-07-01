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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;
	int t = 2, f = 5;
	int num_t = 0, num_f = 0;

	while(n/t > 0){
		num_t += n/t;
		t *= 2;
	}
	while(n/f > 0){
		num_f += n/f;
		f *= 5;
	}
	cout<<min(num_t, num_f);

	//////////////////////

	return 0;
}
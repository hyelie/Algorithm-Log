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
	
	ll A, B, C;
	cin>>A>>B>>C;
	ll result = 1;
	while(B != 0){
		if(B & 1){
			result = (result*A)%C;
		}
		A = (A * A ) % C;
		B >>= 1;
	}

	cout<<result;

	//////////////////////

	return 0;
}
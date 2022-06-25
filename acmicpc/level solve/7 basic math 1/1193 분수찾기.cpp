#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int X; cin>>X;
	int n = 1;
	while(1){
		X -= n;
		n++;
		if(X <= 0) break;
	}
	// X+n-1 : 몇번짼지
	// n : 분모/분자 합
	
	int left = 1-X, right = X+n-1;
	if(n&1){ // 합이 홀수라면
		left = X+n-1, right = 1-X;
		// 분자 = X+n-1, 분모 : 1 - X
	}
	cout<<to_string(left) + "/" + to_string(right);


	return 0;
}
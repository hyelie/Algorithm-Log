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
	
	string A, B, result;
	cin>>A>>B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int up = 0, i, sum, len = max(A.size(), B.size());
	for(i = 0; i<len; i++){
		int avalue = i>=A.length() ? 0 : A[i] - '0';
		int bvalue = i>=B.length() ? 0 : B[i] - '0';
		sum = avalue + bvalue + up;
		up = 0;
		if(sum >= 10){
			sum -= 10;
			up = 1;
		}
		result.push_back(sum+'0');
	}
	if(up==1) result.push_back('1');
	reverse(result.begin(), result.end());
	cout<<result;

	return 0;
}
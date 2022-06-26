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
typedef pair<int, int> pii;

int decompose(int n){
	int answer = n;
	while(n != 0){
		answer += n%10;
		n/=10;
	}
	return answer;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int N; cin>>N;
	for(int i = 1; i<=1000000; i++){
		if(decompose(i) == N){
			cout<<i;
			return 0;
		}
	}
	cout<<"0";

	return 0;
}
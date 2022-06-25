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

	int N; cin>>N;

	for(int i = 2; i<=sqrt(N); i++){
		while(N%i == 0){
			N /= i;
			cout<<i<<'\n';
		}
	}
	if(N > 1) cout<<N;

	return 0;
}
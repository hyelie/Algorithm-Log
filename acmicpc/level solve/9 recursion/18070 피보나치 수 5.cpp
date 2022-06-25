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

int recurse(int N){
	if(N <= 1) return N;
	else return recurse(N-1)  + recurse(N-2);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int N; cin>>N;
	cout<<recurse(N);

	return 0;
}
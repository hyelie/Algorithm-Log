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
vector<pii> results;

void recurse(int from, int temp, int to, int N){
	if(N == 1){
		results.push_back({from, to});
		return;
	}
	recurse(from, to, temp, N-1);
	recurse(from, temp, to, 1);
	recurse(temp, from, to, N-1);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int N; cin>>N;
	recurse(1, 2, 3, N);

	cout<<results.size()<<'\n';
	for(pii p : results){
		cout<<p.first<<' '<<p.second<<'\n';
	}

	return 0;
}
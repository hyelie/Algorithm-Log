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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int N; cin>>N;

	vector<pii> peoples(N);
	for(int i = 0; i<N; i++){
		cin>>peoples[i].first>>peoples[i].second;
	}

	vector<int> ranks(N, 1);
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			if(i == j) continue;
			if(peoples[j].first > peoples[i].first && peoples[j].second > peoples[i].second){
				ranks[i]++;
			}
		}
	}

	for(int r : ranks) cout<<r<<' ';

	return 0;
}
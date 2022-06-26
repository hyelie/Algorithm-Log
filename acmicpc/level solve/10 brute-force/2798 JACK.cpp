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

	int N, M; cin>>N>>M;
	vector<int> cards(N);
	for(int i = 0; i<N; i++){
		cin>>cards[i];
	}

	int answer = -1;
	for(int i = 0; i<N; i++){
		for(int j = i+1; j<N; j++){
			for(int k = j+1; k<N; k++){
				int sum = cards[i] + cards[j] + cards[k];
				if(M < sum) continue;
				answer = max(answer, sum);
			}
		}
	}

	cout<<answer;

	return 0;
}
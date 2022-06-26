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

	vector<string> v(N); // 숫자로 들어오면 문자
	map<string, int> m; // 문자로 들어오면 숫자
	for(int i = 0; i<N; i++){
		cin>>v[i];
		m[v[i]] = i + 1;
	}

	string input;
	while(M--){
		cin>>input;
		if(m.find(input) == m.end()) cout<<v[stoi(input)-1]<<'\n';
		else cout<<m[input]<<'\n';
	}

	return 0;
}
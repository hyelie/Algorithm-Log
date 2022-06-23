#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int N; cin>>N;
	string s;
	int sum = 0;
	cin>>s;
	for(int i = 0; i<N; i++){
		sum += s[i] - '0';
	}
	cout<<sum;
	
	
	return 0;
}
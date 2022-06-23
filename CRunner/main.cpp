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
	
	int P; cin>>P;

	int N; string s;
	while(P--){
		cin>>N>>s;
		for(int i = 0; i<s.size(); i++){
			for(int r = 0; r<N; r++){
				cout<<s[i];
			}
		}cout<<"\n";
	}
	
	
	return 0;
}
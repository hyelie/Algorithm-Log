#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cctype>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	string s; cin>>s;
	vector<int> count(26, 0);
	for(char c : s){
		count[tolower(c)-'a']++;
	}

	int max_value = *max_element(count.begin(), count.end());
	int max_idx = -1;
	int cnt = 0;
	for(int i = 0; i<26; i++){
		if(max_value == count[i]){
			cnt++;
			max_idx = i;
			if(cnt == 2) break;
		}
	}

	if(cnt == 2) cout<<"?";
	else cout<<(char)(max_idx + 'A');
	
	return 0;
}
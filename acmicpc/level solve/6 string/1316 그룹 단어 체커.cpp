#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

bool isGroupWord(string s){
	vector<char> v(s.begin(), s.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<bool> isUsed(26, false);

	for(int i = 0; i<v.size(); i++){
		int idx = v[i] - 'a';
		if(!isUsed[idx]) isUsed[idx] = true;
		else if(isUsed[idx]) return false;
	}
	return true;
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	int N, answer = 0; cin>>N;
	string s;
	while(N--){
		cin>>s;
		if(isGroupWord(s)) answer++;
	}
	cout<<answer;

	
	return 0;
}
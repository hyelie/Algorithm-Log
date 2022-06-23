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

	string s; getline(std::cin, s);
	int spacecnt = 0;
	for(int i = 0; i<s.length(); i++){
		if(s[i] == ' ') spacecnt++;
	}
	if(s[0] == ' ') spacecnt--;
	if(s[s.length()-1] == ' ') spacecnt--;

	cout<<spacecnt + 1;
	
	
	return 0;
}
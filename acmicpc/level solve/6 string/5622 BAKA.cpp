#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

int alphabetToNumber(char c){
	if('A' <= c && c <= 'C') return 2;
	else if('D' <= c && c <= 'F') return 3;
	else if('G' <= c && c <= 'I') return 4;
	else if('J' <= c && c <= 'L') return 5;
	else if('M' <= c && c <= 'O') return 6;
	else if('P' <= c && c <= 'S') return 7;
	else if('T' <= c && c <= 'V') return 8;
	else if('W' <= c && c <= 'Z') return 9;
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);

	string s; cin>>s;
	int result = 0;
	for(int i = 0; i<s.length(); i++){
		result += 1 + alphabetToNumber(s[i]);
	}
	cout<<result;
	
	return 0;
}
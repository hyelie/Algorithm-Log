#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	string s1, s2; cin>>s1>>s2;
	vector<vector<int>> lcs(s1.size(), vector<int>(s2.size(), 1));

	for(int i = 0; i<s1.size(); i++){
		if(s1[i] != s2[0]) lcs[i][0] = 0;
		else break;
	}
	for(int i = 0; i<s2.size(); i++){
		if(s1[0] != s2[i]) lcs[0][i] = 0;
		else break;
	}

	for(int i = 1; i<s1.size(); i++){
		for(int j = 1; j<s2.size(); j++){
			if(s1[i] == s2[j]) lcs[i][j] = lcs[i-1][j-1] + 1;
			else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	cout<<lcs[s1.size()-1][s2.size()-1];

	//////////////////////

	return 0;
}
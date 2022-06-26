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

	////////////////////// write your code below

	string s; cin>>s;
	set<string> ss;

	for(int i = 0; i<s.length(); i++){
		for(int len = 1; len<=s.length(); len++){
			ss.insert(s.substr(i, len));
		}
	}
	cout<<ss.size();

	//////////////////////

	return 0;
}
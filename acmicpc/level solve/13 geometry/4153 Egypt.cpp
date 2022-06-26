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

	vector<int> lines(3);
	while(1){
		cin>>lines[0]>>lines[1]>>lines[2];
		if(lines[0] == 0 && lines[1] == 0 && lines[2] == 0) break;
		sort(lines.begin(), lines.end());
		if(lines[2] * lines[2] == lines[1] * lines[1] + lines[0] * lines[0]) cout<<"right\n";
		else cout<<"wrong\n";
	}

	//////////////////////

	return 0;
}
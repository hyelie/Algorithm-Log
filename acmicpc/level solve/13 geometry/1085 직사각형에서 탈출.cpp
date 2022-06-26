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

	int x, y, w, h;
	cin>>x>>y>>w>>h;
	cout<<min(min(x, w-x), min(y, h-y));

	//////////////////////

	return 0;
}
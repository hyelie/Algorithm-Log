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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int A, B, V;
	cin>>A>>B>>V;

	// A 위로 B 아래로 V 높이

	// (V-A)/(A-B) + 1
	cout<<(int)ceil((double)(V-A)/(A-B)) + 1;


	return 0;
}
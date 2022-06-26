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

bool isContain(int n){
	string s = to_string(n);
	if(s.find("666") == string::npos) return false;
	else return true;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int N; cin>>N;

	int num = 666;
	while(1){
		if(isContain(num)) N--;
		if(N == 0){
			cout<<num;
			break;
		}
		num++;
	}

	return 0;
}
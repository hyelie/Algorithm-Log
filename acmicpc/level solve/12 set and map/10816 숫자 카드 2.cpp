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

	int N, M, input;
	map<int, int> m;

	cin>>N;
	while(N--){
		cin>>input;
		m[input]++;
	}
	
	cin>>M;
	while(M--){
		cin>>input;
		if(m.find(input) == m.end()) cout<<"0 ";
		else cout<<m[input]<<' ';
	}










	//////////////////////

	return 0;
}
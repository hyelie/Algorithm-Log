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

	int N, M;
	cin>>N>>M;
	set<string> s;

	string input;
	while(N--){
		cin>>input;
		s.insert(input);
	}

	vector<string> answer;
	while(M--){
		cin>>input;
		if(s.find(input) != s.end()) answer.push_back(input);
	}

	cout<<answer.size()<<'\n';
	sort(answer.begin(), answer.end());
	for(string str : answer){
		cout<<str<<'\n';
	}

	//////////////////////

	return 0;
}
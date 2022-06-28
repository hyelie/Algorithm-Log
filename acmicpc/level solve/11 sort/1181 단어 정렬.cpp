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

struct cmp{
	bool operator()(const string &a, const string &b) const{
		if(a.length() == b.length()) return a < b;
		return a.length() < b.length(); 
	}
};

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	set<string, cmp> s;
	string input;
	for(int i = 0; i<N; i++){
		cin>>input; s.insert(input);
	}

	for(string str : s){
		cout<<str<<'\n';
	}

	//////////////////////

	return 0;
}
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

void solve(){
	string p; cin>>p;
	int n; cin>>n;
	deque<int> dq;
	string number_list; cin>>number_list;
	number_list = number_list.substr(1, number_list.size()-2);
	int i = 0, prev_i = 0;
	for(i = 0, prev_i = 0; i<number_list.size(); i++){
		if(number_list[i] == ','){
			dq.push_back(stoi(number_list.substr(prev_i, i - prev_i)));
			prev_i = i + 1;
		}
	}
	if(prev_i != i) dq.push_back(stoi(number_list.substr(prev_i)));

	bool isReverse = false; // if true, then pop back. false then pop front
	for(int i = 0; i<p.size(); i++){
		if(p[i] == 'R') isReverse = !isReverse;
		else if(p[i] == 'D'){
			if(dq.size() == 0){
				cout<<"error\n";
				return;
			}
			if(isReverse) dq.pop_back();
			else dq.pop_front();
		}
	}

	string answer = "";
	if(isReverse){
		reverse(dq.begin(), dq.end());
	}
	for(int i : dq){
		answer += to_string(i) + ",";
	}
	cout<<"[" + answer.substr(0, answer.size()-1) + "]\n";
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}
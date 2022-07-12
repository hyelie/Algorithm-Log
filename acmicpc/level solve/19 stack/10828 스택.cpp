#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <stack>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

void solve(){
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	string command;
	int num;
	stack<int> s;
	while(N--){
		cin>>command;
		if(command == "push"){
			cin>>num;
			s.push(num);
		}
		else if(command == "pop"){
			if(s.empty()) cout<<"-1\n";
			else{
				cout<<s.top()<<'\n';
				s.pop();
			}
		}
		else if(command == "size"){
			cout<<s.size()<<'\n';
		}
		else if(command == "empty"){
			cout<<s.empty()<<'\n';
		}
		else{
			if(s.empty()) cout<<"-1\n";
			else cout<<s.top()<<'\n';
		}
	}

	//////////////////////

	return 0;
}
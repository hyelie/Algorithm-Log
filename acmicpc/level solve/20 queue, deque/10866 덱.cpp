#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <deque>
#include <cmath>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	string command; int input;
	deque<int> q;
	while(N--){
		cin>>command;
		if(command == "push_front"){
			cin>>input;
			q.push_front(input);
		}
		else if(command == "push_back"){
			cin>>input;
			q.push_back(input);
		}
		else if(command == "pop_front"){
			if(q.empty()) cout<<"-1\n";
			else{
				cout<<q.front()<<'\n';
				q.pop_front();
			}
		}
		else if(command == "pop_back"){
			if(q.empty()) cout<<"-1\n";
			else{
				cout<<q.back()<<'\n';
				q.pop_back();
			}
		}
		else if(command == "size"){
			cout<<q.size()<<'\n';
		}
		else if(command == "empty"){
			cout<<q.empty()<<'\n';
		}
		else if(command == "front"){
			if(q.empty()) cout<<"-1\n";
			else{
				cout<<q.front()<<'\n';
			}
		}
		else if(command == "back"){
			if(q.empty()) cout<<"-1\n";
			else{
				cout<<q.back()<<'\n';
			}
		}
	}

	//////////////////////

	return 0;
}
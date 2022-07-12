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

void solve(string s){
	stack<char> stk;
	string result = "";
	for(int i = 0; i<s.length(); i++){
		if(s[i] == '(' || s[i] == '['){
			stk.push(s[i]);
		}
		else if(s[i] == ')'){
			if(stk.empty() || stk.top() != '('){
				result = "no";
				break;
			}
			stk.pop();
		}
		else if(s[i] == ']'){
			if(stk.empty() || stk.top() != '['){
				result = "no";
				break;
			}
			stk.pop();
		}
	}
	if(stk.size() != 0 || result == "no") result = "no";
	else result = "yes";
	cout<<result<<'\n';
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	string s;
	while(1){
		getline(cin, s);
		if(s == ".") break;
		solve(s);
	}

	//////////////////////

	return 0;
}
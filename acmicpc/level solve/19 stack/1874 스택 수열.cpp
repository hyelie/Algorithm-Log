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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;
	int inserted_num = 0, input;
	stack<int> s;
	vector<char> answer;
	vector<int> arr(n);
	for(int i = 0; i<n; i++) cin>>arr[i];

	bool able = true;
	for(int i = 0; i<n; i++){
		// 입력값이 '현재까지 삽입한 값'보다 크면 더 넣어야 함
		if(s.empty() || inserted_num < arr[i]){
			while(inserted_num < arr[i]){
				s.push(++inserted_num);
				answer.push_back('+');
			}
		}
		// 입력값이 '현재까지 삽입한 값'보다 작으면
		// stack 어딘가에는 그 입력값이 있을 것임.
		if(inserted_num >= arr[i]){
			bool flag = false;
			while(!s.empty()){ // 그 값을 찾을 때 까지 pop
				if(s.top() == arr[i]){
					flag = true; // 찾으면 true, 계속
				}
				answer.push_back('-');
				s.pop();
				if(flag) break;
			}
			if(!flag){ // 못찾으면 즉시 종료
				able = false;
				break;
			}
		}
		
	}

	if(able){
		for(char c : answer) cout<<c<<'\n';
	} else cout<<"NO";
		

	//////////////////////

	return 0;
}
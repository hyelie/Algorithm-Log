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
#include <stack>
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
	
	int N; cin>>N;

	int input; cin>>input;
	int mid = input; cout<<mid<<'\n';
	priority_queue<int, vector<int>, less<int>> maxh; maxh.push(input);
	priority_queue<int, vector<int>, greater<int>> minh;

	for(int i = 2; i<=N; i++){
		cin>>input;
		if(input < mid){ // max heap에 값 넣어야 하는 경우
			maxh.push(input);
		}
		else{ // min heap에 값 넣어야 하는 경우
			minh.push(input);
		}

		// size를 맞춰 주어야 함. max heap과 min heap의 차이가 최대 1 나게
		// 같다면 max heap쪽으로 몰아 줌
		if(maxh.size() > minh.size() + 1){
			minh.push(maxh.top());
			maxh.pop();
		}
		if(minh.size() >= maxh.size() + 1){
			maxh.push(minh.top());
			minh.pop();
		}
		mid = maxh.top();
		cout<<mid<<'\n';
	}

	//////////////////////

	return 0;
}
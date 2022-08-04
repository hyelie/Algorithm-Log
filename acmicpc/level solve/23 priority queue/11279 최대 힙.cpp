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

void solve(){
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	priority_queue<int, vector<int>, less<int>> pq;
	// vector로 구현하기 때문에 제일 뒤에 있는 것이 들어왔다 나갔다 한다.
	// 즉, vector에서 less는 오름차순. 작은 수가 앞으로, 큰 수가 뒤로 간다 -> pq에서 제일 큰 수가 top이 된다.
	// vector에서 greater는 내림차순. 큰 수가 앞으로, 작은 수가 뒤로 간다 -> pq에서 제일 작은 수가 top이 된다.

	int input;
	while(N--){
		cin>>input;
		if(input == 0){
			if(pq.empty()) cout<<"0\n";
			else{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		}
		else pq.push(input);
	}

	//////////////////////

	return 0;
}
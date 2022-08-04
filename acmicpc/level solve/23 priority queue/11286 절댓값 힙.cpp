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

struct cmp{
	bool operator()(const int &a, const int &b) const{
		if(abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
}; // 내림차순 정렬

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	priority_queue<int, vector<int>, cmp> pq;

	int input;
	while(N--){
		cin>>input;
		if(input == 0){
			if(pq.empty()){
				cout<<"0\n";
			} else{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		}
		else{
			pq.push(input);
		}
	}

	//////////////////////

	return 0;
}
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
	priority_queue<int, vector<int>, greater<int>> pq;

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
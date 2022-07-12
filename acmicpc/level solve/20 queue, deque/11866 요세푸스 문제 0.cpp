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
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N, K; cin>>N>>K;
	queue<int> q;
	for(int i = 1; i<=N; i++) q.push(i);

	vector<int> result;
	int temp_K;
	while(!q.empty()){
		temp_K = K;
		for(int i = 0; i<temp_K-1; i++){
			q.push(q.front());
			q.pop();
		}
		result.push_back(q.front());
		q.pop();
	}

	string answer = "<";
	for(int i : result){
		answer += to_string(i) + ", ";
	}
	cout<<answer.substr(0, answer.length()-2) + ">";

	//////////////////////

	return 0;
}
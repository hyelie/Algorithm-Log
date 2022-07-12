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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N, M; cin>>N>>M;
	int answer = 0, input;
	queue<int> q; for(int i = 1; i<=N; i++) q.push(i);
	for(int i = 0; i<M; i++){
		cin>>input;

		int num_cycle = 0;
		while(q.front() != input){
			q.push(q.front());
			q.pop();
			num_cycle++;
		}
		answer += min(num_cycle, (int)q.size() - num_cycle);
		q.pop();
	}
	cout<<answer;

	//////////////////////

	return 0;
}
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
	
	int N; cin>>N;

	queue<int> q;
	for(int i = 1; i <= N; i++) q.push(i);

	while(q.size() != 1){
		q.pop();
		q.push(q.front()); q.pop();
	}
	cout<<q.front();

	//////////////////////

	return 0;
}
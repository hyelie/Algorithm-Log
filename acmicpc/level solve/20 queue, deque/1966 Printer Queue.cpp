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
	int n, m; cin>>n>>m;
	queue<pii> q; // .first : priority, .second : index
	vector<int> p(n);
	for(int i = 0; i<n; i++){
		cin>>p[i];
		q.push({p[i], i});
	}
	sort(p.begin(), p.end(), greater<int>());

	int cnt = 0;
	for(int i = 0; i<n; i++){
		while(q.front().first < p[i]){
			q.push(q.front());
			q.pop();
		}
		if(q.front().second == m){
			break;
		}
		q.pop();
		cnt++;
	}
	
	cout<<cnt+1<<'\n';

}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}
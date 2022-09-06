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

////////////////////// write your code below

int n, m;

void solve(){
	cin>>n>>m;
    vector<vector<int>> edges(n+1);

    int a, b;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int answer = 0;
    set<int> mst;
    queue<int> next;
    next.push(1);

    while(mst.size() != n){
        int front = next.front(); next.pop();
        if(mst.find(front) == mst.end()){ // not in current, then push
            answer++;
            mst.insert(front);
            for(int adj : edges[front]){
                next.push(adj);
            }
        }
    }
    cout<<answer-1<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
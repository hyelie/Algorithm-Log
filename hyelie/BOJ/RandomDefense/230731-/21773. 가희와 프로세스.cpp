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

struct process{
    int id, time, priority;
};

struct comp{
    bool operator()(const process &a, const process &b){
        if(a.priority == b.priority) return a.id > b.id;
        return a.priority < b.priority;
    }
};

void solve(){
    int T, n; cin>>T>>n;
    priority_queue<process, vector<process>, comp> pq;
    for(int i = 0; i<n; i++){
        process p;
        cin>>p.id>>p.time>>p.priority;
        pq.push(p);
    }

    while(T--){
        process p = pq.top(); pq.pop();
        cout<<p.id<<'\n';
        p.time--;
        if(p.time == 0) continue;
        p.priority--;
        pq.push(p);
    }
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}
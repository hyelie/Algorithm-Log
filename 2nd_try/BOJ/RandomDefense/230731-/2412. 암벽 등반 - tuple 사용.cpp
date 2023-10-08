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

int n, T;
set<pii> V; // == 0 : unvisited, == 1 : visited, 존재 유무는 find()로

int solve(){
	cin>>n>>T;
    int x, y;
    for(int i = 0; i<n; i++){
        cin>>x>>y;
        V.insert({x, y});
    }

    queue<tuple<int, int, int>> q; // 좌표, dist
    q.push({0, 0, 0});
    while(!q.empty()){
        auto [x, y, dist] = q.front(); q.pop();

        // 종료조건
        if(y == T) return dist;

        for(int dx = -2; dx<=2; dx++){
            for(int dy = -2; dy<=2; dy++){
                int nx = x + dx, ny = y + dy;
                if(V.find({nx, ny}) == V.end()) continue; // 없거나 visited인 경우
                V.erase({nx, ny});
                q.push({nx, ny, dist + 1});
            }
        }
    }

    return -1;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	cout<<solve();

	return 0;
}
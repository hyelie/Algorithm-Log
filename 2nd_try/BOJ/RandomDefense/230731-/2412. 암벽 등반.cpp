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
map<pii, int> V; // == 0 : unvisited, == 1 : visited, 존재 유무는 find()로
struct info{
    int x, y, dist;
};

int solve(){
	cin>>n>>T;
    int x, y;
    for(int i = 0; i<n; i++){
        cin>>x>>y;
        V[{x, y}] = 0;
    }

    queue<info> q; // 좌표, dist
    q.push({0, 0, 0});
    while(!q.empty()){
        info cur = q.front(); q.pop();

        // 종료조건
        if(cur.y == T) return cur.dist;

        for(int dx = -2; dx<=2; dx++){
            for(int dy = -2; dy<=2; dy++){
                int nx = cur.x + dx, ny = cur.y + dy;
                if(V.find({nx, ny}) == V.end() || V[{nx, ny}] == 1) continue; // 없거나 visited인 경우
                V[{nx, ny}] = 1;
                info next; next.x = nx; next.y = ny; next.dist = cur.dist + 1;
                q.push(next);
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
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

struct coord{
    int l, r, c;
};

int dr[6] = {1, 0, -1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};
int dl[6] = {0, 0, 0, 0, 1, -1};

string solve(int L, int R, int C){
    coord S, E;
    vector<vector<vector<char>>> dimension(L, vector<vector<char>>(R, vector<char>(C)));
    vector<vector<vector<bool>>> visited(L, vector<vector<bool>>(R, vector<bool>(C, false)));
    for(int l = 0; l<L; l++){
        for(int r = 0; r<R; r++){
            for(int c = 0; c<C; c++){
                cin>>dimension[l][r][c];
                if(dimension[l][r][c] == 'S'){
                    S.l = l; S.r = r; S.c = c;
                }
                else if(dimension[l][r][c] == 'E'){
                    E.l = l; E.r = r; E.c = c;
                }
            }
        }
    }

    queue<pair<coord, int>> q;
    q.push({S, 0});
    visited[S.l][S.r][S.c] = true;
    while(!q.empty()){
        coord f = q.front().first; int fmin = q.front().second; q.pop();
        if(f.l == E.l && f.r == E.r && f.c == E.c){
            return "Escaped in " + to_string(fmin) + " minute(s).";
        }
        
        for(int i = 0; i<6; i++){
            int nl = f.l + dl[i];
            int nr = f.r + dr[i];
            int nc = f.c + dc[i];
            if(0 <= nl && nl < L && 0 <= nr && nr < R && 0 <= nc && nc < C && dimension[nl][nr][nc] != '#' && !visited[nl][nr][nc]){
                q.push({{nl, nr, nc}, fmin + 1});
                visited[nl][nr][nc] = true;
            }
        }
    }
    return "Trapped!";
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

    int L, R, C;
    while(1){
        cin>>L>>R>>C;
        if(L == 0 && R == 0 && C == 0) break;
        cout<<solve(L, R, C)<<'\n';
    }

	return 0;
}
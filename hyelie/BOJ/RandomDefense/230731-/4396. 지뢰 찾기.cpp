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

int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void solve(){
	int n; cin>>n;
    vector<vector<bool>> isMine(n, vector<bool>(n, false)); // mine(*)이면 true, else false
    vector<vector<int>> numMine(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char input; cin>>input;
            if(input == '*'){
                isMine[i][j] = true;
                for(int d = 0; d<8; d++){
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if(0 <= nr && nr < n && 0 <= nc && nc < n){
                        numMine[nr][nc]++;
                    }
                }
            }
        }
    }

    bool isExplode = false;
    vector<vector<bool>> isInput(n, vector<bool>(n, false)); // isInput(x)면 true, else false
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char input; cin>>input;
            if(input == 'x'){
                isInput[i][j] = true;
                if(isMine[i][j]) isExplode = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(isExplode && isMine[i][j]) cout<<'*';
            else if(isInput[i][j]) cout<<numMine[i][j];
            else cout<<'.';
        }
        cout << '\n';
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
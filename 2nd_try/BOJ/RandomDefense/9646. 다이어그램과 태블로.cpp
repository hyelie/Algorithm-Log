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

int k, N, num_col[8], board[8][8], answer;
// num_col[i] : i번째 row의 col 개수

// recurse(row, col) - row, col에서 backtrack
void recurse(int row, int col){
    // top-down recurse 종료조건
    if(row == 0 && num_col[row] <= col){
        answer++;
        return;
    }

    // 위/왼쪽 보고 가능한 숫자부터 recurse. 세로부터 채움.
    int s = 1;
    if(row > 0) s = max(s, board[row-1][col] + 1); // 위
    if(col > 0) s = max(s, board[row][col-1]); // 왼
    for(int i = s; i<=N; i++){
        board[row][col] = i;
        if(num_col[row+1] > col){ // 아래칸으로 내릴 수 있으면 내리고, 그렇지 않으면 바로 다음 col로 감.
            recurse(row+1, col);
        }
        else{
            recurse(0, col+1);
        }
    }
}

void solve(){
	while(1){
        cin>>k;
        if(cin.eof()) return;

        for(int i = 0; i<8; i++) num_col[i] = 0;
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                board[i][j] = 0;
            }
        }

        for(int i = 0; i<k; i++) cin>>num_col[i];
        cin>>N;
        answer = 0;
        recurse(0, 0);
        cout<<answer<<"\n";
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
// 가장 큰 정사각형

#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board){
    int row = board.size(), col = board[0].size(), maxlen = -1;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for(int i = 0; i<row; i++) dp[i][0] = board[i][0];
    for(int i = 0; i<col; i++) dp[0][i] = board[0][i];
    
    
    for(int i = 1; i<row; i++){
        for(int j = 1; j<col; j++){
            if(board[i][j]){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
            maxlen = max(maxlen, dp[i][j]);
        }
    }
    return maxlen * maxlen;
}

/*
옛날에 좀 고생했던 dp였던걸로 기억한다....
row, col size <= 1000이기 때문에 brute-force로 접근하면 정사각형 길이가 500일 때, 500 * 500(전부 1인지 검사) * 500 * 500(총 1000 by 1000에서 500 * 500짜리는 500 * 500번 존재가능)이므로 5^4*100000000으로, 불가능
따라서 다른 방법이 필요하다.

dp[i][j] : (0, 0)에서 (i, j)까지 탐색했을 때 i, j를 포함하는 정사각형의 최대 변의 길이
따라서 board[i][j] == 0일 때는 값이 0이고, board[i][j]가 1일 때 정사각형을 만들 '수도 있다'
따라서 board[i][j] == 1일 때만 점화식이 들어가며
dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1로 나타낼 수 있다.
 - 정사각형을 만드는 경우, 만들지 않는 경우 모두 설명 가능.
 - 새로 정사각형을 만드는 경우 : min(~) + 1로 새로운 정사각형이 만들어졌다는 것을 앎.
 - 새로 정사각형이 만들어지지 않는 경우 : 아무리 커 봤자, 
*/












/*
int solution(vector<vector<int>> board)
{
    int row = board.size(), col = board[0].size();
    int max_len = -1;
    
    vector<vector<int>> dp(row, vector<int>(col));
    
    // (n, 0) 초기화
    for(int i = 0; i<row; i++){
        if(board[i][0] == 1) dp[i][0] = 1;
        else dp[i][0] = 0;
    }
    // (0, n) 초기화
    for(int j = 0; j<col; j++){
        if(board[0][j] == 1) dp[0][j] = 1;
        else dp[0][j] = 0;
    }

    // DP 실행
    for(int i = 1; i<row; i++){
        for(int j = 1; j<col; j++){
            // 정사각형이 더 커질 수 있는 상황 : 위, 왼쪽도 정사각형이고, 좌상단 대각선도 정사각형이었을 때
            // 이걸 어떻게 판별할까
            if(board[i][j] == 1){
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            }
            max_len = max(dp[i][j], max_len);
        }
    }
    

    if(max_len == -1) return 1;
    return max_len * max_len;
}*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int SIZE = 3;

// 끝나는 조건 : 세로 3줄, 가로 3줄, 대각 2개
bool isEnd(vector<string> &board, char c){
    string s = "";
    for(int i = 0; i<SIZE; i++) s += c;
    
    for(int i = 0; i<3; i++){
        if(board[i] == s) return true;
    }
    
    for(int i = 0; i<3; i++){
        string vertical = "";
        for(int j = 0; j<3; j++){
            vertical += board[j][i];
        }
        if(vertical == s) return true;
    }
    
    string digonal1 = "", digonal2 = "";
    for(int i = 0; i<3; i++){
        digonal1 += board[i][i];
        digonal2 += board[2 - i][i];
    }
    if(digonal1 == s) return true;
    if(digonal2 == s) return true;
    
    return false;
}
int solution(vector<string> board) {
    // 둔 수 계산
    int ocount = 0, xcount = 0;
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            if(board[i][j] == 'O') ocount++;
            if(board[i][j] == 'X') xcount++;
        }
    }
    // 조건 하나. X가 O보다 더 많이 둔 경우 : 불가능
    if(xcount > ocount){
        return 0;
    }
    // 조건 둘. O는 X보다 같거나, 1개 더 많은 수를 둘 수 있다.
    if(ocount > xcount + 1){
        return 0;
    }

    // 끝남 여부 계산
    bool isOEnd = isEnd(board, 'O'), isXEnd = isEnd(board, 'X');

    // 조건 셋. X가 완성시킨 시점에서 O가 한 수 더 놓는 것은 불가능
    if(isXEnd && ocount > xcount){
        return 0;
    }
    
    // 조건 넷. O가 완성시킨 시점에서 X가 한 수 더 놓는 것은 불가능
    if(isOEnd && ocount <= xcount){
        return 0;
    }
    
    return 1;
}
// 크레인 인형뽑기

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int board_size = board.size();
    vector<stack<int>> v_s(board_size);
    for(int i = board_size-1; i >= 0; i--){
        for(int j = 0; j<board_size; j++){
            if(board[i][j]) v_s[j].push(board[i][j]);
        }
    }
    
    vector<int> bucket(1001, 0);
    int bucket_idx = 0, cnt = 0;
    for(int elem : moves){
        // 안 비었으면 stack에서 pop, bucket에 push
        if(!v_s[elem-1].empty()){
            bucket[bucket_idx] = v_s[elem-1].top();
            v_s[elem-1].pop();
            
            // 만약 bucket에서 동일한 인형이 있는 경우 해당 인형 무시해야 함
            while(bucket_idx > 0 && bucket[bucket_idx-1] == bucket[bucket_idx]){
                bucket_idx -= 2;
                cnt += 2;
            }
            bucket_idx++;
        }
    }
    
    return cnt;
}

/*

[
[0,0,0,0,0],
[0,0,1,0,3],
[0,2,5,0,1],
[4,2,4,4,2],
[3,5,1,3,1]
]
이렇게 두면 제일 top에 있는 걸 검사하기 힘드니까 각 col을 stack으로, 바꾸자
v_s[i] : board의 i번째 col에 있는 인형 순서들.
[
[3,4] (col 0의 순서)
[5,2,2]
[1,4,5,1]
[3,4]
[1,2,1,3]
]

*/
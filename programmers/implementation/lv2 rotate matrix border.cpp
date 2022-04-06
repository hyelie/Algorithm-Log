// 행렬 테두리 회전하기

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int rotate(vector<vector<int>>& v, vector<int> point){
    int x1 = point[0], y1 = point[1], x2 = point[2], y2 = point[3];
    int width = y2 - y1, height = x2 - x1;
    int top_right = v[x1][y2], bot_left = v[x2][y1];
    int minval = min(top_right, bot_left);
    
    for(int i = 0 ; i<width; i++){
        v[x1][y2 - i] = v[x1][y2 - i - 1];
        v[x2][y1 + i] = v[x2][y1 + i + 1];
        minval = min(min(minval,  v[x1][y2 - i]), v[x2][y1 + i]);
    }
    for(int i = 0; i<height; i++){
        v[x1 + i][y1] = v[x1 + i + 1][y1];
        v[x2 - i][y2] = v[x2 - i - 1][y2];
        minval = min(min(minval, v[x1 + i][y1]), v[x2 - i][y2]);
    }
    v[x1 + 1][y2] = top_right;
    v[x2 - 1][y1] = bot_left;
    return minval;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    // {queries[i][0], queries[i][1]}부터 {queries[i][2], queries[i][3]}까지 1칸 시계방향 회전.
    // 위치기 바뀐 숫자 중 제일 작은 숫자를 배열에 담음.
    // rows, cols <= 100 -> 1만.
    // 1번 회전에 최대 400번 연산, 
    
    int cnt = 1;
    vector<vector<int>> v(rows+1, vector<int>(columns+1, 0));
    for(int i = 1; i<=rows; i++){
        for(int j = 1; j<=columns; j++){
            v[i][j] = cnt++;
        }
    }
    
    int size = queries.size();
    vector<int> answer(size);
    for(int i = 0; i<size; i++){
        answer[i] = rotate(v, queries[i]);
    }
    
    return answer;
}
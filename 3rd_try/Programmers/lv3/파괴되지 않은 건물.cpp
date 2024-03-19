#include <string>
#include <vector>

using namespace std;

int maxr, maxc;

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    maxr = board.size(); maxc = board[0].size();
    vector<vector<int>> datas(maxr+1, vector<int>(maxc+1, 0));
    
    // psum set 
    for(vector<int>& skill : skills){
        int type = skill[0], r1 = skill[1], c1 = skill[2], r2 = skill[3], c2 = skill[4], degree = skill[5];
        if(type == 1) degree *= -1;
        
        datas[r1][c1] += degree;
        datas[r1][c2 + 1] -= degree;
        datas[r2 + 1][c1] -= degree;
        datas[r2 + 1][c2 + 1] += degree;
    }
    
    // 오른쪽으로 psum 
    for(int i = 0; i<maxr; i++){
        for(int j = 1; j<maxc; j++){
            datas[i][j] += datas[i][j-1];
        }
    }
    // 아래쪽으로 pusm
    for(int i = 1; i<maxr; i++){
        for(int j = 0; j<maxc; j++){
            datas[i][j] += datas[i-1][j];
        }
    }
    
    // psum 결과 봄
    int answer = 0;
    for(int i = 0; i<maxr; i++){
        for(int j = 0; j<maxc; j++){
            if(board[i][j] + datas[i][j] > 0) answer++;
        }
    }
    
    return answer;
}

/*
2차원 psum
*/
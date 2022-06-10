// 파괴되지 않은 건물

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M;
typedef pair<int, int> pii;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    N = board.size(); M = board[0].size();
    vector<vector<int>> datas(N, vector<int>(M, 0));
    
    for(vector<int> v : skill){
        int type = v[0], r1=v[1], c1=v[2], r2=v[3], c2=v[4], degree=v[5];
        if(type==1) degree *= -1;
        
        datas[r1][c1] += degree;
        if(c2 + 1 < M) datas[r1][c2 + 1] -= degree;
        
        if(r2 + 1 < N) datas[r2 + 1][c1] -= degree;
        if(r2 + 1 < N && c2 + 1 < M) datas[r2+1][c2+1] += degree;
    }
    
    for(int r =0; r<N; r++){
        for(int c =1; c<M; c++){
            datas[r][c] += datas[r][c-1];
        }
    }
    for(int c =0; c<M; c++){
        for(int r=1; r<N; r++){
            datas[r][c] += datas[r-1][c];
        }
    }
    
    int answer = 0;
    for(int r =0 ;r<N; r++){
        for(int c =0; c<M; c++){
            if(board[r][c] + datas[r][c]>0) answer++;
        }
    }    
    
    return answer;
}

/*

각 r에 모든 공사 시작지점 c1, c2, deg 넣고 -> 25만
r 개수는 1000개
각 r별로 공사지점을 O(n)에 알 수 있을까?
공사 시작 지점 + degree / 공사 끝 지점 + degree를 r에 넣음 : 25만
'현재 더하는 값'을 둠.
공사 시작 지점을 만나면 '현재 더하는 값' + degree
공사 끝 지점을 만나면 '현재 더하는 값' - degree
이렇게 풀면 1차원 누적 합임.
이래도 O(NK)라 시간초과 -> 2차원 누적합이 필요.


*/
// 등굣길

#include <string>
#include <vector>
#include <map>

using namespace std;
int MOD = 1000000007;

    // row : n, col : m
int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> num(n, vector<int>(m, 0)); // num[i][j] : 시작부터 i, j까지 경로 개수
    vector<vector<bool>> is_puddle(n, vector<bool>(m, false)); // grid[i][j] : (i, j) 좌표에 웅덩이
    for(vector<int> v : puddles){
        is_puddle[v[1]-1][v[0]-1] = true;
    }
    int answer = 0;
    
    num[0][0] = 1;
    for(int r = 1; r<n; r++){
        if(is_puddle[r][0]) break;
        num[r][0] = num[r-1][0];
    }
    for(int c = 1; c<m; c++){
        if(is_puddle[0][c]) break;
        num[0][c] = num[0][c-1];
    }
    
    for(int r = 1; r<n; r++){
        for(int c = 1; c<m; c++){
            if(is_puddle[r][c]) continue;
            num[r][c] = (num[r-1][c] % MOD + num[r][c-1] % MOD) % MOD;
        }
    }
    
    return num[n-1][m-1];
}
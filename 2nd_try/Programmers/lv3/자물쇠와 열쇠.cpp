#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M;

// remove
void print(vector<vector<int>> &v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v.size(); j++){
            cout<<v[i][j]<<' ';
        }cout<<endl;
    }
    cout<<endl;
}

// 오른쪽으로 90도 회전
vector<vector<int>> rotate(vector<vector<int>> &key){
    vector<vector<int>> rotated_key(M, vector<int>(M, 0));
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            rotated_key[j][M-1-i] = key[i][j];
        }
    }
    return rotated_key;
}

// total 초기화 함수
// total 중에서 lock의 시작 위치는 (M-1, M-1)부터 (M+N-2, M+N-2)까지임.
void initTotal(vector<vector<int>> &total, vector<vector<int>> &lock){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            total[i+M-1][j+M-1] = lock[i][j];
        }
    }
}

// lock이 가득 찼는지 확인하는 함수
// total 중에서 lock의 시작 위치는 (M-1, M-1)부터 (M+N-2, M+N-2)까지임.
bool isLockFull(vector<vector<int>> &total){
    int end = M+N-2;
    for(int i = M-1; i<=end; i++){
        for(int j = M-1; j<=end; j++){
            if(total[i][j] != 1) return false;
        }
    }
    return true;
}

// total에서 key의 시작 위치가 (r, c)일 때 key를 더하고 확인하는 함수
bool isMatch(vector<vector<int>> total, vector<vector<int>>& key, int r, int c){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            total[i+r][j+c] += key[i][j];
        }
    }
    return isLockFull(total);
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size(); N = lock.size();
    
    // 회전된 key들 생성
    vector<vector<vector<int>>> keys;
    keys.push_back(key);
    for(int i = 0; i<3; i++){
        key = rotate(key);
        keys.push_back(key);
    }
    
    // size 충분한 한 배열 생성. 가운데에 lock이 들어가고, key들은 위치를 옮겨가며 가득 차는지 볼 것임.
    int total_size = N+2*M-2;
    vector<vector<int>> total(total_size, vector<int>(total_size));
    initTotal(total, lock);
    
    // key의 시작 위치는 (0, 0부터) (M+N-1, M+N-1)까지 가능.
    int end = M+N-1;
    for(int i = 0; i<end; i++){
        for(int j = 0; j<end; j++){
            for(int k = 0; k<4; k++){
                if(isMatch(total, keys[k], i, j)) return true;
            }
        }
    }
    return false;
}
/*
가운데 lock 두고
상하좌우에 key만큼 size 추가함
그러면 N + 2M짜리. 
*/
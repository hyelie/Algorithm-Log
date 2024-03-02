#include <string>
#include <vector>
#include <iostream>

using namespace std;

int m, n;

void print(vector<vector<int>>& v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            cout<<v[i][j]<<'\t';
        }cout<<endl;
    }
    cout<<endl;
}

vector<vector<vector<int>>> keys;

vector<vector<int>> rotate(vector<vector<int>>& origin){
    vector<vector<int>> result(m, vector<int>(m, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            result[j][m - i - 1] = origin[i][j];
        }
    }
    
    return result;
}

// lock 부분이 모두 1인지
bool Is_Lock_All_One(vector<vector<int>>& lock){
    for(int i = m-1; i<m-1+n; i++){
        for(int j = m-1; j<m-1+n; j++){
            if(lock[i][j] != 1) return false;
        }
    }
    return true;
}

// r, c 위치에 key를 뒀을 때 lock이 풀리는지 여부
bool Can_Insert(vector<vector<int>>& lock, vector<vector<int>>& key, int r, int c){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            lock[i+r][j+c] += key[i][j];
        }
    }
        
    bool is_lock_all_one = Is_Lock_All_One(lock);
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            lock[i+r][j+c] -= key[i][j];
        }
    }
    
    return is_lock_all_one;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    m = key.size(); n = lock.size();

    // 가능한 모든 key의 rotated version
    keys.push_back(key);
    for(int i = 0; i<3; i++){
        key = rotate(key);
        keys.push_back(key);
    }
    // for(vector<vector<int>> key : keys) print(key); // for debug

    // lock + key 모두 들어갈 수 있게 lock 확장
    int new_lock_size = 2*m+n - 2;
    vector<vector<int>> new_lock(new_lock_size, vector(new_lock_size, 0));
    for(int i = m; i<m+n; i++){
        for(int j = m; j<m+n; j++){
            new_lock[i-1][j-1] = lock[i-m][j-m];
        }
    }
    // print(new_lock); // for debug
    
    // 모든 가능한 위치에 모든 key 넣으면서 bf
    for(int i = 0; i<m+n-1; i++){ // m+n-1
        for(int j = 0; j<m+n-1; j++){
            for(int k = 0; k<4; k++){
                bool can_insert = Can_Insert(new_lock, keys[k], i, j);
                if(can_insert) return true;
            }
        }
    }
    return false;
}

/*
시간 계산
(2 * key + lock) ^ 2 size에서
key * key * (key + lock) * (key + lock)
1600
400
640000
시간은 충분.
*/
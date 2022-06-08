// 자물쇠와 열쇠

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> m){
    vector<vector<int>> a(m[0].size(), vector<int>(m.size()));
    
    for(int r = 0; r<a.size(); r++){
        for(int c= 0; c<a[0].size(); c++){
            a[r][c] = m[c][m[0].size()-1-r];
        }
    }
    return a;
}

bool isMatching(vector<vector<int>>& nlock, int sr, int sc, int num_slot, vector<vector<int>>& key){
    int nlocksize = nlock.size(), keysize = key.size();
    int cnt = 0;
    for(int r = 0; r < keysize; r++){
        for(int c = 0; c<keysize; c++){
            if(nlock[sr + r][sc + c] == 2) continue;
            if(nlock[sr + r][sc + c] == 1 && key[r][c] == 1) return false;
            if(nlock[sr + r][sc + c] == 0 && key[r][c] == 0) return false;
            if(nlock[sr + r][sc + c] == 0 && key[r][c] == 1) cnt++;
        }
    }
    return cnt == num_slot;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // keysize <= locksize
    int keysize = key.size(), locksize = lock.size(), nlocksize = locksize + 2 * keysize - 2;
    vector<vector<int>> nlock(nlocksize, vector<int>(nlocksize, 2));
    int num_slot = 0;
    for(int r = 0; r<locksize; r++){
        for(int c = 0; c<locksize; c++){
            nlock[r + keysize-1][c + keysize-1] = lock[r][c];
            if(lock[r][c] == 0)num_slot++;
        }
    }
    
    vector<vector<vector<int>>> keys;
    keys.push_back(key);
    for(int i = 0; i<4; i++){
        keys.push_back(rotate(keys[keys.size()-1]));
    }
    
    
    for(int lr = 0; lr < nlocksize - keysize + 1; lr++){
        for(int lc = 0; lc < nlocksize - keysize + 1; lc++){
            for(int i = 0; i<4; i++){
                bool result = isMatching(nlock, lr, lc, num_slot, keys[i]);
                if(result) return true;
            }
        }
    }
    
    return false;
}
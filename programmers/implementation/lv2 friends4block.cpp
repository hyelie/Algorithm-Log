// 프렌즈4블록

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pii;

// .first : row, .second : col
// second는 내림차순으로, first는 오름차순으로
struct comp{
    bool operator() (const pii&a, const pii&b) const{
        if(a.first == b.first){
            return a.second > b.second;
        } else{
            return a.first < b.first;
        }
    }
};


int solution(int m, int n, vector<string> board) {
    vector<vector<char>> v(n, vector<char>(m));
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            v[n-j-1][m-i-1] = board[i][j];
        }
    }
    
    // TTTANT
    // RRFACC
    // RRRFCC
    // TRRRAA
    // TTMMMF
    // TMMTTJ를

    // J F A C C T 
    // T M A C C N 
    // T M R F A A 
    // M M R R F T 
    // M T R R R T 
    // T T T R R T로 바꿔 줌. (m, 0), (0, n)의 대각선 기준 대칭이동임.
    
    // 왼쪽이 바닥쪽임.
    /*for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }*/
    
    int num_removed = 0, temp_removed = -1;
    while(num_removed != temp_removed){
        temp_removed = num_removed;
        int r_size = v.size(), c_size;
        set<pii, comp> remove_set;
        for(int i = 0; i<r_size; i++){
            c_size = v[i].size();
            for(int j = 0; j<c_size; j++){
                if(0 <= i + 1 && i + 1 < r_size && 0 <= j + 1 && j + 1 < c_size
                   && v[i][j] == v[i][j+1] && v[i][j] == v[i+1][j] && v[i][j] == v[i+1][j+1]){
                    remove_set.insert({i, j});
                    remove_set.insert({i, j+1});
                    remove_set.insert({i+1, j});
                    remove_set.insert({i+1, j+1});
                }
            }
        }
        
        num_removed += remove_set.size();
        
        for(pii elem : remove_set){
            v[elem.first].erase(v[elem.first].begin() + elem.second);
        }
    }
    
    
    return num_removed;
}

/*

TTTANT
RRFACC
RRRFCC
TRRRAA
TTMMMF
TMMTTJ

J F A C C T 
T M A C C N 
T M R F A A 
M M R R F T 
M T R R R T 
T T T R R T

J F A T 
T M A N 
T M R F A A 
M M F T 
M T T 
T T T T

왼쪽으로 모으면 됨.(v.erase 하면 된다는 뜻.)

*/
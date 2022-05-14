// 공 이동 시뮬레이션

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 원래 direction
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

typedef pair<int, int> pii;
typedef long long ll;

int handle(int value, int max){
    if(value < 0) return 0;
    if(value >= max) return max-1;
    return value;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    int size = queries.size();
    ll rs = x, re = x, cs = y, ce = y;
    for(int i = size-1; i>=0; i--){
        int dir = queries[i][0], space = queries[i][1];
        if(dir == 2){ // up
            if(rs == 0){
                re += space;  
            } else{
                rs += space;
                re += space;
            }
            re = handle(re, n);
        } else if(dir == 3){ // down
            if(re == n-1){
                rs -= space;
            } else{
                rs -= space;
                re -= space;
            }
            rs = handle(rs, n);
        } else if(dir == 0){ // left
            if(cs == 0){
                ce += space;
            } else{
                cs += space;
                ce += space;
            }
            ce = handle(ce, m);
        }else{ // right
            if(ce == m-1){
                cs -= space;
            } else{
                cs -= space;
                ce -= space;
            }
            cs = handle(cs, m);
        }
        if(rs > n-1 || re < 0 || cs > m-1 || ce < 0) return 0;
        // 이런 반례 : 2 by 2에서 target이 (0, 1)이고 query가 left로만 가는 경우 -> 역추적하면 cs가 오른쪽으로 넘어감
    }

    return (ce - cs + 1) * (re - rs + 1);
}
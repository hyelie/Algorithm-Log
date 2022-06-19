// 몸짱 트레이너 라이언의 고민

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
typedef pair<int, int> pii;

int getDist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
    // 누적합 알고리즘으로 최대 몇 명이 겹치는 지 쉽게 알 수 있음
    int start_time = 600;
    vector<int> times(721, 0);
    for(vector<int> vi : timetable){ // 시작하는 부분에 +1, 끝나는 부분에 -1을 하고
        times[vi[0] - start_time]++;
        times[vi[1] - start_time+1]--;
    }
    for(int i = 1; i<=720; i++){ // 누적합 해버리면 최대로 겹치는 사람의 명 수를 알 수 있음.
        times[i] += times[i-1];
    }
    
    // max_overlap은 worst n*n의 size임.
    // cutting ? 거리가 d인 곳에만 두는 방식 ?
    // 최대 거리 2n-1
    // 총 50번 탐색
    // 한 번의 탐색에 이전까지 둔 모든 locker를 봄 - 50번
    // n^5인 듯?
    // 다시 한 번 생각을 바꿔서, 'dist'가 주어졌을 때 dist를 유지하면서 최대로 넣을 수 있는 인원을 가져와 보자
    int max_overlap = *max_element(times.begin(), times.end());
    
    int chessboard_num = n * n / 2 + n % 2; // chessboard처럼 채울 경우
    if(max_overlap == 1) return 0;
    if(max_overlap == 2) return 2 * n - 2;
    if(max_overlap > chessboard_num) return 1;
    
    int target_dist;
    for(target_dist = 2*n-3; target_dist >= 3; target_dist--){
        for(int rs = 0; rs<n; rs++){
            for(int cs = 0; cs<n; cs++){
                // {rs, cs} : 탐색 시작점 / row_start, col_start
                vector<pii> lockers;
                lockers.push_back({rs, cs});

                int max_people = -1;

                // row_start보다 위에는 넣지 않겠음.
                for(int cr = rs; cr<n; cr++){
                    for(int cc = 0; cc<n; cc++){
                        // {cr, cc} : 현재 보는 위치 / current_row, current_col
                        bool canInsert = true;
                        for(int lockeridx = 0; lockeridx < lockers.size(); lockeridx++){
                            if(getDist(lockers[lockeridx], {cr, cc}) < target_dist){
                                canInsert = false;
                                break;
                            }
                        }

                        if(canInsert == false){
                            continue;
                        }
                        lockers.push_back({cr, cc});
                    }
                }
                if(max_overlap == lockers.size()) return target_dist;
            }
        }
    }
    
    
    return target_dist;
}

/*
1명이면 0
2명이면 2n
3명이면 n?
4명이면 n
5명이면 

규칙이 없다!

일단 brute-force로 풀어야 함.

확실한 건 chessboard처럼 채울 경우가 거리가 2인 최대 선임!
그것보다 크다면 1 리턴하는 건 확실함.
*/
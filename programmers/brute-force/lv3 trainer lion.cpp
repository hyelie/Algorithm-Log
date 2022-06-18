// 몸짱 트레이너 라이언의 고민

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> pii;

void backtrack(int cur_depth, int max_depth, int prev_idx, int& max_dist, vector<pii>& results, vector<pii>& able_points){
    if(cur_depth == max_depth){
        int cur_min_dist = 999999;
        for(int i = 0; i<max_depth; i++){
            for(int j = i+1; j<max_depth; j++){
                cur_min_dist = min(cur_min_dist, abs(results[i].first - results[j].first) + abs(results[i].second - results[j].second));
            }
        }
        if(max_dist < cur_min_dist){
            /*cout<<"갱신, 값 : "<<cur_min_dist<<endl;
            for(int i = 0; i<max_depth; i++){
                cout<<results[i].first<<" "<<results[i].second<<endl;
            }*/
        }
        max_dist = max(max_dist, cur_min_dist);
        return;
    }
    
    for(int i = prev_idx + 1; i<able_points.size(); i++){
        results[cur_depth] = able_points[i];
        backtrack(cur_depth+1, max_depth, i, max_dist, results, able_points);
    }
    
    return;
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
    // n*n C x임
    // 100 C 50은 1억을 훨씬 넘음
    // 조금 더 효율적 알고리즘이 필요하지 싶음
    // cutting ? 거리가 d인 곳에만 두는 방식 ?
    // 최대 거리 2n-1
    // 총 50번 탐색
    // 한 번의 탐색에 이전까지 둔 모든 locker를 봄 - 50번
    // n^5인 듯?
    int max_overlap = *max_element(times.begin(), times.end());
    
    int chessboard_num = n*n/2 + n%2; // chessboard처럼 채울 경우
    cout<<"chess"<<chessboard_num<<endl;
    if(max_overlap > chessboard_num) return 1;
    
    
    vector<pii> results(max_overlap);
    int max_dist = -1;
    
    vector<pii> able_points;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            able_points.push_back({i, j});
        }
    }
    
    backtrack(0, max_overlap, -1, max_dist, results, able_points);
    
    cout<<max_dist<<endl;
    if(max_dist == 999999) max_dist = 0;
    
    return max_dist;
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
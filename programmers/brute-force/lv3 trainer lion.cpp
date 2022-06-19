// 몸짱 트레이너 라이언의 고민

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
typedef pair<int, int> pii;

int getDist(pii&a, pii&b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// return {r, c} in range
bool inRange(int r, int c, int n){
    if(0 <= r && r < n && 0 <= c && c < n) return true;
    else return false;
}

// cur_point로부터 거리가 D인 모든 점
vector<pii> getDistDPoints(int D, pii cur_point, int n){
    set<pii> result;
    pii top = {cur_point.first - D, cur_point.second};
    pii bottom = {cur_point.first + D, cur_point.second};
    
    int dr[2] = {1, 1};
    int dc[2] = {1, -1};
    
    for(int i = 0; i<=D; i++){
        for(int lr = 0; lr < 2; lr++){
            pii p = {top.first + i * dr[lr], top.second + i * dc[lr]};    
            if(inRange(p.first, p.second, n)) result.insert(p);
            
            p = {bottom.first - i * dr[lr], bottom.second - i * dc[lr]};
            if(inRange(p.first, p.second, n)) result.insert(p);
        }
    }
    
    vector<pii> to_v(result.begin(), result.end());
    return to_v;
}

bool backtrack(int cur_depth, int max_depth, int target_dist, vector<pii>& results, vector<pii> cur_able_points, int n){
    if(cur_depth == max_depth-1){
        return true;
    }
    
    for(int i = 0; i<cur_able_points.size(); i++){
        pii next_point = cur_able_points[i];
        results[cur_depth] = next_point;
        
        vector<pii> dist_d_points = getDistDPoints(target_dist, next_point, n);
        vector<pii> next_able_points;
        
        for(int dpi = 0; dpi < dist_d_points.size(); dpi++){
            bool isAllDistOverD = true;
            for(int cdi = 0; cdi <= cur_depth; cdi++){
                if(getDist(results[cdi], dist_d_points[dpi]) < target_dist){
                    isAllDistOverD = false;
                    break;
                }
            }
            if(isAllDistOverD) next_able_points.push_back(dist_d_points[dpi]);
        }
        
        if(next_able_points.size() == 0) return false;
        else{
            bool flag = backtrack(cur_depth+1, max_depth, target_dist, results, next_able_points, n);
            if(flag) return true;
        }
    }
    return false;
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
    int max_overlap = *max_element(times.begin(), times.end());
    
    int chessboard_num = n * n / 2 + n % 2; // chessboard처럼 채울 경우
    if(max_overlap == 1) return 0;
    if(max_overlap == 2) return 2 * n - 2;
    if(max_overlap > chessboard_num) return 1;
    
    vector<pii> results(max_overlap);
    int max_dist = -1, target_dist;
    vector<pii> cur_able_points;
    for(int r = 0; r<n; r++){
        for(int c= 0; c<n; c++){
            cur_able_points.push_back({r, c});
        }
    }
    for(target_dist = 2*n-3; target_dist >= 3; target_dist--){
        bool flag = backtrack(0, max_overlap, target_dist, results, cur_able_points, n);
        if(flag) break;
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
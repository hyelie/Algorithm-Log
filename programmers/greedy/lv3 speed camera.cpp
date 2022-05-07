// 단속카메라

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector<int> vi;

bool cmp(vi &a, vi &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    // 나간 시점 기준 오름차순 정렬
    sort(routes.begin(), routes.end(), cmp);
    
    // 첫 차가 나가는 시점에 캠을 박음.
    int cam_point = routes[0][1], cnt = 1;
    for(vi v : routes){
        if(v[0] <= cam_point) continue; // 다음 차가 캠에 걸리는 위치라면 어차피 걸리니까 상관없음
        else{ // 캠에 걸리지 않는 위치라면 해당 차의 제일 뒤에 박음.
            cam_point = v[1];
            cnt++;
        }
    }
    
    return cnt;
}
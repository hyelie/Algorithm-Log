#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            if(a[2] == b[2]){
                return a[3] < b[3];
            }
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    vector<vector<int>> guards(scope.size());
    // [i][0] : 경계 시작 지점, [i][1] : 경계 끝 지점
    // [i][2] : 근무 시간, [i][3] : 휴식 시간
    for(int i = 0; i<scope.size(); i++){
        if(scope[i][0] > scope[i][1]){
            guards[i].push_back(scope[i][1]);
            guards[i].push_back(scope[i][0]);
        }
        else{
            guards[i].push_back(scope[i][0]);
            guards[i].push_back(scope[i][1]);
        }
        guards[i].push_back(times[i][0]);
        guards[i].push_back(times[i][1]);
    }
    sort(guards.begin(), guards.end(), cmp);

    int answer = distance;
    for(vector<int>& guard : guards){
        int cycle_time = guard[2] + guard[3];
        // 감시하는 구간에 근무시간이라면 break
        // 어떤 i가 근무 시간에 있는 건...
        // 1 <= (i % cycle_time) <= guard[2]
        // 이면 근무 시간이라는 것을 판별할 수 있음
        for(int i = guard[0]; i<=guard[1]; i++){
            int remainder = i%cycle_time;
            if(1 <= remainder &&  remainder <= guard[2]){
                answer = min(answer, i);
            }
        }
    }
    
    return answer;
}
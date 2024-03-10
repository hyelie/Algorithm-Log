#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> apeach;
int NINF = -1e9;
int max_score_diff = NINF;
vector<int> answer = {-1};

bool cmp(vector<int>& a, vector<int> &b){
    for(int i = 10; i>=0; i--){
        if(a[i] == b[i]) continue;
        return a[i] > b[i];
    }
}

int get_score_diff(vector<int> &lion){
    int apeach_point = 0, lion_point = 0;
    for(int i = 0; i<10; i++){
        if(apeach[i] == 0 && lion[i] == 0) continue;
        if(apeach[i] >= lion[i]) apeach_point += 10-i;
        else lion_point += 10-i;
    }
    
    return lion_point - apeach_point;
}

void backtrack(int cur_depth, int max_depth, int used_arrow, int max_arrow, vector<int> &lion){
    if(used_arrow == max_arrow || cur_depth == max_depth){
        // 점수 계산 후 정답 갱신
        lion[10] = max_arrow - used_arrow;
        int score_diff = get_score_diff(lion);
        
        if(score_diff <= 0) return;
        if(score_diff < max_score_diff) return;
        if(score_diff > max_score_diff){
            max_score_diff = score_diff;
            answer = lion;
        }
        if(max_score_diff == score_diff){
            answer = cmp(answer, lion) ? answer : lion;
        }
        
        return;
    }
    
    
    if(used_arrow + apeach[cur_depth] + 1 <= max_arrow){
        lion[cur_depth] = apeach[cur_depth] + 1;
        backtrack(cur_depth + 1, max_depth, used_arrow + apeach[cur_depth] + 1, max_arrow, lion);
    }
    
    lion[cur_depth] = 0;
    backtrack(cur_depth+1, max_depth, used_arrow, max_arrow, lion);
}

vector<int> solution(int _n, vector<int> _apeach) {
    n = _n; apeach = _apeach;
    
    vector<int> lion(11, 0);
    backtrack(0, 10, 0, n, lion);
    
    return answer;
}

/*
2^10 모든 경우의 수 나열
각 경우의 수에 대해
  불가 -> 리턴
  가능 -> 점수 계산
    점수 높음 -> 갱신
    점수 같음 -> 비교, 갱신
    점수 낮음 -> 버림
*/
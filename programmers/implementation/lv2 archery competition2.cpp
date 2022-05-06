// 양궁대회

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> apeach, answer;
int point_differ = -1;

// a가 우선순위 -> true, b가 우선순위 -> false
bool cmp(vector<int> &a, vector<int> &b){
    //vector 거꾸로 보고 수가 더 커야 함
    for(int i = 10; i>=0; i--){
        if(a[i] > b[i]) return true;
        else if(a[i] == b[i]) continue;
        else return false;
    }
}

pii calResult(vector<int> lion){
    int cur_point;
    pii result = {0, 0}; // .first : apeach, .second : lion point
    for(int i = 0; i<=10; i++){
        cur_point = 10-i;
        if(apeach[i] + lion[i] == 0) continue;
        if(apeach[i] >= lion[i]) result.first += cur_point;
        else result.second += cur_point;
    }
    return result;
}

void DFS(int depth, int max_depth, int num_arrows, vector<int>& lion){
    if(depth == max_depth || num_arrows == 0){
        lion[10] = num_arrows;
        pii point_result = calResult(lion);
        int apeach_point = point_result.first, lion_point = point_result.second;
        if(apeach_point >= lion_point) return;
        
        if(lion_point - apeach_point > point_differ){
            point_differ = lion_point - apeach_point;
            answer = lion;
        }
        else if(lion_point - apeach_point == point_differ){
            answer = cmp(answer, lion)?answer : lion;
        }
        return;
    }
    
    // 점수를 얻을 수 있어서 점수를 얻겠다고 선택하는 경우
    int apeach_point = apeach[depth];
    if(num_arrows >= apeach_point + 1){
        lion[depth] = apeach_point + 1;
        DFS(depth+1, max_depth, num_arrows - apeach_point - 1, lion);
        lion[depth] = 0;
    }
    
    // 점수를 얻을 수 있든 말든 점수를 얻지 않는다고 선택하는 경우
    DFS(depth+1, max_depth, num_arrows, lion);
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    vector<int> lion(11, 0);
    answer = {-1};
    
    DFS(0, 9, n, lion);
    r
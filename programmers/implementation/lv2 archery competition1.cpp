// 양궁대회

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> apeach, answer;
int point_differ = 0;

typedef pair<int, int> pii;

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

// arr : size n, 뽑을 숫자들
// result : size r, 뽑힌 숫자들.
void duplicateCombination(int depth, int r, int prev_idx, vector<int>& arr, vector<int>& result){
    if(depth == r){
        vector<int> lion(11, 0);
        for(int i : result) lion[i]++;
        pii point = calResult(lion);
        int lion_point = point.second, apeach_point = point.first;  
        if(point_differ < lion_point - apeach_point){
            answer = lion;
            point_differ = lion_point - apeach_point;
        }
        if(point_differ == lion_point - apeach_point){
            answer = cmp(lion, answer)? lion : answer;
        }
        return;
    }
    
    for(int i = prev_idx; i<arr.size(); i++){
        result[depth] = arr[i];
        duplicateCombination(depth+1, r, i, arr, result);   
    }
}

vector<int> solution(int n, vector<int> info) {
    
    answer = {-1};
    apeach = info;
    vector<int> areas = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> combinations(n);
    duplicateCombination(0, n, 0, areas, combinations);
    
    return answer;
}

/*

11개의 서로 다른 구역 중 n개를 뽑는 방법 (=같은 화살 10개를 11개의 구역에 놓는 방법) -> 중복조합.
-> 11H10

*/
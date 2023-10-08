#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// stat[i][j] : i번째 학생이 종목 j의 능력치
// vertex가 
/*
DP vs graph vs BF
앞 단에서 최대값을 택한다고, 전체가 최대가 되는 게 아님. -> BF 써야 하긴 하는데.
worst 10^10
*/

// 일단 DFS
int answer = -1e9;
vector<vector<int>> stats;
vector<bool> isSelected; // isSelected[i] : i번째 학생을 골랐는지 여부
int student_num, event_num;
void DFS(int cur_d, int max_d, int result){
    if(cur_d == max_d){
        answer = max(answer, result);
        return;
    }
    
    for(int i = 0; i<student_num; i++){
        if(!isSelected[i]){
            isSelected[i] = true;
            DFS(cur_d + 1, max_d, result + stats[i][cur_d]);
            isSelected[i] = false;
        }
    }
}


int solution(vector<vector<int>> input) {
    stats = input;
    student_num = input.size();
    event_num = input[0].size();
    isSelected.resize(student_num);
    fill(isSelected.begin(), isSelected.end(), false);
    
    DFS(0, event_num, 0);
    
    return answer;
}
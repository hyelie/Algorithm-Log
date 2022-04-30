// 타겟 넘버

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;

void DFS(int cur_depth, int max_depth, vector<bool>& sign, vector<int> &numbers, int target){
    if(cur_depth == max_depth){
        int size = numbers.size(), sum = 0;
        for(int i = 0; i<size; i++){
            sum += numbers[i] * (sign[i] ? 1 : -1);
        }
        if(sum == target) cnt++;
        return;
    }

    sign[cur_depth] = true;
    DFS(cur_depth+1, max_depth, sign, numbers, target);
    sign[cur_depth] = false;
    DFS(cur_depth+1, max_depth, sign, numbers, target);
}
    
int solution(vector<int> numbers, int target) {
    int size = numbers.size();
    vector<bool> sign(size);
    
    DFS(0, size, sign, numbers, target);
    
    return cnt;
}
    
    
    
    
    
    
    
    
    
    
    

/*
// op[i] == true : i번째 숫자는 더함.
void DFS(int depth, int maxdepth, int target, vector<int> &num, vector<bool> &op, int &answer){
    if(depth == maxdepth){
        int cal = 0, opnum = num.size();
        for(int i = 0; i<opnum; i++){
            cal += op[i]? num[i] : -1*num[i];
        }
        if(cal == target) answer++;
        return;
    }
    
    op[depth] = true;
    DFS(depth+1, maxdepth, target, num, op, answer);
    op[depth] = false;
    DFS(depth+1, maxdepth, target, num, op, answer);
    return;
}

int solution(vector<int> numbers, int target) {
    int num_num = numbers.size();
    vector<bool> op(num_num, true);
    int answer = 0;
    DFS(0, num_num, target, numbers, op, answer);
    return answer;
}*/

// 2^n을 DFS
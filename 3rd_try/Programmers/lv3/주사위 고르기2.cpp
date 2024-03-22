#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int num_dice;
vector<vector<int>> dices;

int num_max_win = 0;
vector<int> answer;

void print(vector<int>& v){
    for(int i : v) cout<<i<<", ";
    cout<<endl;
}

void point_backtrack(int cur_depth, int max_depth, vector<int> &choice, int sum, vector<int>& result){
    if(cur_depth == max_depth){
        result.push_back(sum);
        return;
    }
    
    for(int i = 0; i<6; i++){
        point_backtrack(cur_depth + 1, max_depth, choice, sum + dices[choice[cur_depth]][i], result);
    }
}

void calculate(vector<int> &choice){
    // choice split
    vector<int> a_choice, b_choice;
    for(int i = 0; i<num_dice; i++){
        if(choice[i]) a_choice.push_back(i);
        else b_choice.push_back(i);
    }
    
    // a, b의 모든 경우의 수 점수 구함
    vector<int> a_points, b_points;
    point_backtrack(0, a_choice.size(), a_choice, 0, a_points);
    point_backtrack(0, b_choice.size(), b_choice, 0, b_points);
    
    // b에서 lower bound index = a의 승리 회수
    sort(b_points.begin(), b_points.end(), less<int>());
    int num_a_win = 0;
    for(int a_point : a_points){
        num_a_win += lower_bound(b_points.begin(), b_points.end(), a_point) - b_points.begin();
    }
    
    // 갱신
    if(num_a_win > num_max_win){
        num_max_win = num_a_win;
        answer = a_choice;
    }
}

void dice_backtrack(int cur_depth, int max_depth, int prev_idx, vector<int> &result){
    if(cur_depth == max_depth){
        calculate(result);
        return;
    }
    
    for(int i = prev_idx+1; i<num_dice; i++){
        result[i] = true;
        dice_backtrack(cur_depth+1, max_depth, i, result);
        result[i] = false;
    }
}

vector<int> solution(vector<vector<int>> _dices) {
    dices = _dices;
    num_dice = dices.size();
    vector<int> result(num_dice);
    dice_backtrack(0, num_dice / 2, -1, result);
    
    for(int &i : answer) i++;
    return answer;
}

/*
10개 중 5개 가져가기: 256
각 경우의 수에 대해
    A의 모든 주사위 눈의 경우의 수 6 ^ 5 = 7776 = 10000정도로
    B의 모든 주사위 눈의 경우의 수 = 10000
    10000 log 10000 = 130000
=> 350만
*/
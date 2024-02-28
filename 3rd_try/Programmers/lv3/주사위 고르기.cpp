#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<vector<int>> comb; // a가 고르는 주사위 index가 들어 있음
vector<vector<int>> options; // n개 주사위를 굴렸을 때 나올 수 있는 모든 경우의 수.

// a가 고르는 주사위 index 전체 목록
void getComb(int cur_depth, int prev_idx, vector<int>& result){
    if(cur_depth == n / 2){
        vector<int> temp(result.begin(), result.end());
        comb.push_back(temp);
        return;
    }
    
    for(int i = prev_idx+1; i<n; i++){
        result[cur_depth] = i;
        getComb(cur_depth + 1, i, result);
    }
}

// a가 고르지 않은 주사위 index vector
vector<int> getOtherComb(vector<int>& acomb){
    set<int> s;
    for(int i = 0; i<n; i++) s.insert(i);
    
    for(int i : acomb) s.erase(i);
    
    vector<int> bcomb(s.begin(), s.end());
    return bcomb;
}

// max_depth개 주사위를 골랐을 때 모든 경우의 수 목록
void dfsOptions(int cur_depth, int max_depth, vector<int> &result){
    if(cur_depth == max_depth){
        options.push_back(result);
        return;
    }
    
    for(int i = 0; i<6; i++){
        result[cur_depth] = i;
        dfsOptions(cur_depth + 1, max_depth, result);
    }
}

// 주사위 indexes 조합에 대해, option 선택지에 대해 점수값
int getValue(vector<int> &indexes, vector<int> &option, vector<vector<int>> &dice){
    int sum = 0;
    for(int i = 0; i<n/2; i++){
        int dice_index = indexes[i];
        int option_index = option[i];
        sum += dice[dice_index][option_index];
    }
    return sum;
}

vector<int> solution(vector<vector<int>> dice) {
    n = dice.size();
    
    vector<int> temp_result(n/2);
    getComb(0, -1, temp_result);
    
//     for(vector<int> &arr : comb){
//         for(int i : arr) cout<<i<<", ";
//         cout<<endl;
        
//         vector<int> bcomb = getOtherComb(arr);
//         for(int i : bcomb) cout<<i<<", ";
//         cout<<endl;
//         cout<<endl;
        
//     }
    
    dfsOptions(0, n/2, temp_result);
    // for(vector<int> &arr : options){
    //     for(int i : arr) cout<<i<<", ";
    //     cout<<endl;
    // }
    
    vector<int> answer;
    int max_win = -1;
    
    for(vector<int> &acomb : comb){ // 300개
        // acomb, bcomb : a, b가 고른 주사위 index가 나와 있음.
        vector<int> bcomb = getOtherComb(acomb);
        
        // 모든 선택지에 대해, a가 고른 것, b가 고른 것을 구함.
        vector<int> aValues, bValues;
        for(vector<int>& option : options){ // 3만개
            int aValue = getValue(acomb, option, dice);
            aValues.push_back(aValue);
            int bValue = getValue(bcomb, option, dice);
            bValues.push_back(bValue);
        }
        
        // a 정렬, b의 모든 elem에 대해 a에서 upper bound index를 구함.
        // 해당 index : b가 이기거나 지는 경우의 수. 전체 - 해당 index => a가 이기는 경우의 수.
        // sort(aValues.begin(), aValues.end());
        // int asum = 0;
        // int len = aValues.size();
        // for(int bValue : bValues){
        //     int index = upper_bound(aValues.begin(), aValues.end(), bValue) - aValues.begin();
        //     asum += (len - index);
        // }
        
        // 이렇게 해도 된다. b 정렬 이후 a의 lb index : a가 이기는 경우의 수.
        sort(bValues.begin(), bValues.end());
        int asum = 0;
        int len = aValues.size();
        for(int aValue : aValues){
            int index = lower_bound(bValues.begin(), bValues.end(), aValue) - bValues.begin();
            asum += index;
        }
        
        // 값 갱신
        if(max_win < asum){
            max_win = asum;
            answer = acomb;
        }
    }
    
    for(int &i : answer) i++;
    
    return answer;
}
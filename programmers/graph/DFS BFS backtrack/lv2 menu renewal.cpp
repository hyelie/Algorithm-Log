// 메뉴 리뉴얼

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

void comb(int cur_d, int max_d, int prevIdx, vector<bool>& isUsed, string totalS, string combS, unordered_map<string, int> &um){
    if(cur_d == max_d){        
        sort(combS.begin(), combS.end());
        if(um.find(combS) == um.end()){
            um[combS] = 1;
        } else{
            um[combS] += 1;
        }
        return;
    }

    for(int i = prevIdx + 1; i<isUsed.size(); i++){
        isUsed[i] = true;
        comb(cur_d+1, max_d, i, isUsed, totalS, combS + totalS[i], um);
        isUsed[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int course_num : course){
        unordered_map<string, int> um;
        for(string order : orders){
            vector<bool> isUsed(order.length(), false);
            comb(0, course_num, -1, isUsed, order, "", um);
        }

        // um에서 value가 제일 높은 값을 찾아서 push
        int max_value = -1;
        for(auto [key, value] : um){
            if(value > 1) max_value = max(value, max_value);
        }
        for(auto [key, value] : um){
            if(value == max_value) answer.push_back(key);
        }
    }

    sort(answer.begin(), answer.end());


    return answer;
} 
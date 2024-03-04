#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, string> parents; // [이름, 추천인]
unordered_map<string, int> sums; // [이름, 총액]

void sell(string name, int value){ // name이 value만큼 판 경우
    // 90%를 자기가 가진다. 원 단위에서 절사
    while(name != "-" && value != 0){
        int give = value / 10;
        sums[name] += (value - give);
        
        name = parents[name];
        value = give;
    }
    
    return;
}

vector<int> solution(vector<string> enrolls, vector<string> referrals, vector<string> sellers, vector<int> amounts) {
    // edge 연결
    for(int i = 0; i<enrolls.size(); i++){
        string enroll = enrolls[i], referral = referrals[i];
        parents[enroll] = referral;
    }
    
    // 
    for(int i = 0; i<sellers.size(); i++){
        string seller = sellers[i];
        int amount = amounts[i] * 100;
        sell(seller, amount);
    }
    
    // 계산
    vector<int> answer(enrolls.size());
    for(int i = 0; i<enrolls.size(); i++){
        string enroll = enrolls[i];
        answer[i] = sums[enroll];
    }
    return answer;
}
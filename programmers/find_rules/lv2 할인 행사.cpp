#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int isMatch(map<string, int>&m){
    for(auto& [key, value] : m){
        if(value > 0) return 0;
    }
    return 1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> m;
    
    int wantSize = want.size();
    for(int i = 0; i<wantSize; i++){
        m[want[i]] = number[i];
    }   
    
    int answer = 0;
    int windowSize = 10;
    
    for(int i = 0; i<windowSize; i++){
        if(m.find(discount[i]) != m.end()){
            m[discount[i]]--;
        }
    }
    answer += isMatch(m);
    
    int discountSize = discount.size();
    for(int i = 1; i<discountSize - windowSize + 1; i++){
        // slide 이동, 첫 부분 뺌
        if(m.find(discount[i-1]) != m.end()){
            m[discount[i-1]]++;
        }
        // 끝 부분 추가함
        if(m.find(discount[i + windowSize - 1]) != m.end()){
            m[discount[i + windowSize - 1]]--;
        }
        answer += isMatch(m);
    }
    
    return answer;
}
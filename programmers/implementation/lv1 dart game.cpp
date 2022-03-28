// [1차] 다트 게임

#include <string>
#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int pow(int base, int exp){
    int result = 1;
    while(exp--){
        result *= base;
    }
    return result;
}

// isdigit(), isalpha() 함수를 잘 써보자.

int solution(string dartResult) {
    vector<int> point(3, 0);    // 각 round의 점수
    vector<int> bonus(3, 0);    // 각 round의 bouns, 1, 2, 3으로 저장함.
    vector<int> option(3, 1);  // 아무것도 없는 경우 1, *인 경우 2, #인 경우 -1
    
    int length = dartResult.length();
    for(int i = 0, idx = -1; i<length; i++){
        if(isdigit(dartResult[i])){
             idx++;
            string num = "";
            while(i < length && isdigit(dartResult[i])){
                num += dartResult[i];
                i++;
            }
            point[idx] = stoi(num);
        }
        if(dartResult[i] == 'S'){
            bonus[idx] = 1;
        }
        else if(dartResult[i] == 'D'){
            bonus[idx] = 2;
        }
        else if(dartResult[i] == 'T'){
            bonus[idx] = 3;
        }
        else if(dartResult[i] == '*'){
            option[idx] = 2;
        }
        else if(dartResult[i] == '#'){
            option[idx] = -1;
        }
    }

    
    for(int i = 0; i<3; i++){
        point[i] = pow(point[i], bonus[i]);
    }
    
    point[0] *= option[0];
    for(int i = 1; i<3; i++){
        point[i] *= option[i];
        if(option[i] == 2) point[i-1] *= option[i];
    }


    return accumulate(point.begin(), point.end(), 0);
}
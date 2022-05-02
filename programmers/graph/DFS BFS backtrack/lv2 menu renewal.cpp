// 순위 검색

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// 조건을 4진수로 바꿔주는 함수.
// 언어 : 1의자리. cpp - 1, java - 2, python - 3, - - 0
// 직군 : 2번째 자리. backend - 1, frontend - 2, - - 0
// 경력 : 3번째 자리. junior - 1, senior - 2, - - 0
// 소울푸드 : 4번째 자리. chicken - 1, pizza - 2, - - 0
// ex. java backend junior pizza : 2112 -> 2 + 4 + 16 + 128 = 150
int conditionToNum(vector<string> v){
    int digit = 1, result = 0;
    string s;
    for(int i = 0; i<v.size(); i++){
        s = v[i];
        if(s == "-") result += digit * 0;
        else if(s == "cpp" || s == "backend" || s == "junior" || s == "chicken") result += digit*1;
        else if(s == "java" || s == "frontend" || s == "senior" || s == "pizza") result += digit*2;
        else if(s == "python") result += digit*3;
        digit *= 4;
    }
    return result;
}

vector<int> changeCondition(vector<string> v){
    vector<string> cases = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                     "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    vector<string> backup(v.begin(), v.end());
    vector<int> result;
    for(string c : cases){
        for(int i = 0; i<4; i++){
            v[i] = backup[i];
        }
        
        for(int i = 0; i<4; i++){
            if(c[i] == '1'){
                v[i] = "-";
            }
        }
        
        result.push_back(conditionToNum(v));
    }
    
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    
    
    /*vector<string> test = {"java", "backend", "junior", "pizza"};
    vector<int> testi = changeCondition(test);
    for(int i : testi){
        cout<<i<<endl;
    }*/
    
    int num_cases = 256;
    istringstream iss; string buffer;
    vector<vector<int>> point_vector(num_cases); // point_vector[i] : 조건이 i인 사람들의 점수
    for(string s : info){
        iss.clear(); iss.str(s);
        vector<string> data;
        while(getline(iss, buffer, ' ')){
            data.push_back(buffer);
        } data.pop_back();
        
        vector<int> all_cases = changeCondition(data);
        for(int c : all_cases){
            point_vector[c].push_back(stoi(buffer));
        }
    }
    
    for(vector<int> &v : point_vector){
        sort(v.begin(), v.end());
    }
    
   
    
    vector<int> answer;
    vector<int>::iterator iter;
    for(string s : query){
        iss.clear(); iss.str(s);
        vector<string> question;
        while(getline(iss, buffer, ' ')){
            if(buffer == "and") continue;
            question.push_back(buffer);
        } question.pop_back();
        
        vector<int> target = point_vector[conditionToNum(question)];
        iter = lower_bound(target.begin(), target.end(), stoi(buffer));
        answer.push_back(target.end() - iter);
    }
    
    return answer;
}

// simple하게 푼다면, 50,000 * 100,000 = 5,000,000,000 (50억)이므로 시간 초과임.
// nlogn으로 풀어라는 문제이다.
// info를 tree 형식으로 만든다면 쉽게 풀 수 있을 것 같은데.
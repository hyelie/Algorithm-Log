#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> termMap;

int date2int(string date){ // date : YYYY.MM.DD 형식
    int year = stoi(date.substr(0, 4)) - 2000;
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    
    return day + month * 28 + year * 28 * 12;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    for(string str : terms){
        termMap[str.substr(0, 1)] = stoi(str.substr(2));
    }
    
    int currentDay = date2int(today);
    
    vector<int> answer;
    for(int i = 0; i<privacies.size(); i++){
        int privacyDay = date2int(privacies[i].substr(0, 10));
        string privacyType = privacies[i].substr(11);
        
        int expiredDay = privacyDay + 28 * termMap[privacyType] - 1; // 개월 수 * 28
        if(currentDay > expiredDay) answer.push_back(i+1);
    }

    return answer;
}

/*
골자
모든 date를 day로 바꾸어서 계산할 것임
map을 시용해 terms 종류에 따른 유효기간을 저장하고
privacies를 순회하며 day로 바꾼 날짜를 비교하면 됨

유의점
시작 날짜 + 12개월 -> 1년 후의 그 날짜가 나오는데
시작 날짜도 포함시켜야 하기 때문에 -1을 해 주어야 함.

0:35분
*/
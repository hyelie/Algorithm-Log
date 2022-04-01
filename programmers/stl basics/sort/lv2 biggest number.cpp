// 가장 큰 수

#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool comp(int &f, int &s){
    string a = to_string(f), b = to_string(s);
    if(a + b > b + a) return true;
    else return false;
}

string solution(vector<int> numbers) {
    int size = numbers.size();
    sort(numbers.begin(), numbers.end(), comp);
    
    string answer = "";
    for(int s : numbers){
        answer += to_string(s);
    }
    if(answer[0] == '0') return "0";
    return answer == "" ? "0" : answer;
}

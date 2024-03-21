#include <string>
#include <vector>
#include <iostream>

using namespace std;

// n 길이로 s 압축 시 결과
string compress(string s, int n){
    string result = "";
    int start_index = 0;
    while(start_index < s.length()){
        string parts = s.substr(start_index, n);
        int count = 1;
        start_index += n;
        while(start_index < s.length() && s.substr(start_index, n) == parts){
            start_index += n;
            count++;
        }
        if(count != 1) result += to_string(count);
        result += parts;
    }
    return result;
}

int solution(string s) {
    int answer = 1001;
    for(int i = 1; i<=s.length() / 2 + 1; i++){
        string compressed_string = compress(s, i);
        int compressed_length = compressed_string.length();
        answer = min(answer, compressed_length);
    }
    return answer;
}
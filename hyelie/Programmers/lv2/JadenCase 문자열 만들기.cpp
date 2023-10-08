// 7분에 다 풀고 제출했음.
// 5분 더 풀고 다 맞음
/*
놓쳤던 점은 제일 마지막에 공백이 올 수 있다는 것이었음.
나의 경우 공백을 delimiter로 사용했다 보니 마지막에 오는 경우를 처리할 수 없었음.
*/

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s){
    vector<string> result;
    istringstream iss(s);
    string buffer;
    
    while(getline(iss, buffer, ' ')){
        result.push_back(buffer);
    }
    
    return result;
}

string tolower(string s){
    for(char &c : s){
        if(isupper(c)) c = tolower(c);
    }
    return s;
}

string toJadenCase(string s){
    if(islower(s[0])){
        s[0] = toupper(s[0]);
    }
    return s;
}

string solution(string s) {
    int len = s.length();
    for(int i = len-1; i>=1; i--){
        if(isupper(s[i])) s[i] = tolower(s[i]);
        if(s[i-1] == ' ') s[i] = toupper(s[i]);
    }
    if(islower(s[0])) s[0] = toupper(s[0]);
    return s;
    
    
    /*vector<string> parsed_string = split(s);
    for(string &s : parsed_string){
        s = tolower(s);
        s = toJadenCase(s);
    }
    
    string answer = "";
    int len = parsed_string.size();
    for(int i = 0; i<len-1; i++){
        answer += parsed_string[i] + " ";
    }
    answer += parsed_string[len-1];
    if(s[s.length()-1] == ' ') answer += " ";
    
    return answer;*/
}
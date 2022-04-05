// 괄호 회전하기

#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isRight(string s){
    stack<char> stk;
    for(char c : s){
        switch(c){
            case '[':
            case '{':
            case '(':
                stk.push(c);
                break;
            case '}':
                if(stk.empty() || stk.top() != '{')
                    return false;
                else stk.pop();
                break;
            case ']':
                if(stk.empty() || stk.top() != '[')
                    return false;
                else stk.pop();
                break;
            case ')':
                if(stk.empty() || stk.top() != '(')
                    return false;
                else stk.pop();
                break;
        }
    }
    return stk.empty();
}

int solution(string s) {
    int answer = 0, len = s.length();
    
    for(int i = 0; i<len; i++){
        if(isRight(s.substr(i, len-i) + s.substr(0, i))){
            answer++;
        }
    }
    
    return answer;
}
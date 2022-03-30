// 올바른 괄호

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s){
    int n = 0;
    for(char c : s){
        if(c == '(') n++;
        else if(c == ')') n--;
        
        if(n < 0) return false;
    }
    return (n == 0) ? true : false;
    
}








/*

bool solution(string s)
{
    bool answer = true;

    stack<char> stk;
    
    int sSize = s.size();
    for(int i = 0; i<sSize; i++){
        if(stk.empty()){
            stk.push(s[i]);
        }
        else{
            if(s[i] == ')' && stk.top() == '('){
                stk.pop();
            }
            else stk.push(s[i]);
        }
    }

    return stk.empty();
}*/
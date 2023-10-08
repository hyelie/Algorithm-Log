#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    for(char c : s){
        if(c == ')'){
            if(stk.empty() || stk.top() != '(') return false;
            stk.pop();
        }
        else if(c == '('){
            stk.push('(');
        }
    }
    
    return stk.empty();
}
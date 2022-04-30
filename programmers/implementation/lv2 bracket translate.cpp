// 괄호 변환

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isBalanced(string s){
    int bs = 0, be = 0;
    for(char c : s){
        if(c == ')') be++;
        else if(c == '(') bs++;
    }
    if(be == bs) return true;
    else return false;
}

bool isRight(string s){
    stack<char> stk;
    for(char c : s){
        if(c == ')'){
            if(stk.empty()) return false;
            if(stk.top() == '(') stk.pop();
        }
        else if(c == '('){
            stk.push(c);
        }
    }
    
    if(!stk.empty()) return false;
    return true;
}
           
string reverseBracket(string s){
    for(char &c : s){
        if(c == ')'){
            c = '(';
        }
        else if(c == '('){
            c = ')';
        }
    }
    return s;
}

string solve(string w){
    int wlen = w.length();
    if(wlen == 0) return "";
    string u, v;
    
    for(int i = 1; i <= wlen; i++){
        u = w.substr(0, i);
        v = w.substr(i%wlen, w.length()-i);
        if(isBalanced(u) && isBalanced(v)) break;
    }
    
    if(isRight(u)){
        v = solve(v);
        u += v;
        return u;
    } else{
        string temp = "(";
        temp += solve(v);
        temp += ")";
        temp += reverseBracket(u.substr(1, u.length()-2));
        return temp;
    }
}

string solution(string p) {
    return solve(p);
}
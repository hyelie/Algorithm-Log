// 짝지어 제거하기

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string s){
    if(s.length() & 1) return 0;
    
    stack<char> stk;
    for(char c : s){     
        if(stk.empty()){
            stk.push(c);
        } else{
            if(stk.top() == c) stk.pop();
            else stk.push(c);
        }
    }

    return stk.empty();
}

// nlogn

/*
int solution(string s)
{
    int answer = 0, prev_len = 0, cur_len = 1;
    if(s.length() & 1) return 0;
    
    while(prev_len != cur_len){
        prev_len = s.length();
        for(int i = 1; i<s.length(); i++){
            if(s[i-1] == s[i]){
                s.erase(i-1, 2);
            }
        }
        cur_len = s.length();
    }
    

    return s=="";
}
*/
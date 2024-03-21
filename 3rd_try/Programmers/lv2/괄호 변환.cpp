#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_balanced(string& str){
    int num_open = 0, num_close = 0;
    for(char c : str){
        if(c == '(') num_open++;
        else num_close++;
    }
    return num_open == num_close;
}

bool is_correct(string &str){
    int num_open = 0;
    for(int i = 0; i<str.length(); i++){
        if(str[i] == '(') num_open++;
        else num_open--;
        
        if(num_open < 0) return false;
    }
    return num_open == 0;
}

void rev(string &str){
    for(char &c : str){
        if(c == ')') c = '(';
        else c = ')';
    }
}

string solution(string p) {
    // 1.
    if(p.length() == 0) return "";
    if(is_correct(p)) return p;
    
    // 2. u, v로 분리: u는 최소
    string u, v;
    for(int i = 2; i<=p.length(); i += 2){
        u = p.substr(0, i);
        if(is_balanced(u)){
            v = p.substr(i);
            break;
        }
    }
    
    // 3. 
    if(is_correct(u)){
        return u + solution(v);
    }
    
    // 4.
    // 4-1 ~ 4-3
    string new_v = "(" + solution(v) + ")";
    // 4-4
    string cut_u = u.substr(1, u.length()-2);
    rev(cut_u);
    
    return new_v + cut_u;
}
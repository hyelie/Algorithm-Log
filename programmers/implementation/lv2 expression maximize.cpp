// 수식 최대화

#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// c가 operatior인지 판별
bool isOP(char c){
    if(c == '+' || c == '-' || c == '*') return true;
    else return false;
}

// c는 operator, a와 b는 숫자. a와 b를 c연산 한 후 string으로 리턴
string cal_operand(string c, string a, string b){
    long long result = 0, all = stoll(a), bll = stoll(b);
    if(c == "-"){
        result = all - bll;
    }else if(c == "*"){
        result = all * bll;
    }else if(c == "+"){
        result = all + bll;
    }
    return to_string(result);
}

// list와 operator의 우선순위 ops가 주어졌을 때 결과 계산 후 리턴
long long calculate(list<string> l, string ops){
    long long max_value = 0;
    list<string>::iterator iter, prv, nxt;
    for(int i = 0; i<ops.length(); i++){
        string temp = ""; temp.push_back(ops[i]);
        for(iter = l.begin(); iter != l.end(); iter++){
            if(*iter == temp){
                prv = prev(iter, 1);
                nxt = next(iter, 1);
                *iter = cal_operand(*iter, *prv, *nxt);
                l.erase(prv); 
                l.erase(nxt);
            }
        }
    }
    
    return abs(stoll(*l.begin()));
}

long long solution(string expression) {
    list<string> l;
    int length = expression.length();
    for(int i = 0, prev = 0; i<length; i++){
        prev = i;
        while(i < length && !isOP(expression[i])) i++;
        l.push_back(expression.substr(prev, i-prev));
        if(i < length){
            string temp = ""; temp.push_back(expression[i]);
            l.push_back(temp);    
        }
    }
    
    vector<string> cases = {"*+-", "*-+", "-+*", "-*+", "+-*", "+*-"};
    
    long long r = 0;
    for(int i = 0; i<cases.size(); i++){
        r = max(r, calculate(l, cases[i]));
    }
    
    return r;
}

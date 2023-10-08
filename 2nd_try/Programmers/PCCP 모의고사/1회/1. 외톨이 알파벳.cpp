#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

string solution(string str) {
    stack<char> stk;
    for(char c : str){
        if(!stk.empty() && stk.top() == c) continue;
        stk.push(c);
    }
    
    map<char, int> m;
    while(!stk.empty()){
        m[stk.top()]++;
        stk.pop();
    }
    
    string answer = "";
    for(auto &[key, value] : m) {
        if(value > 1) answer += key;
    }
    sort(answer.begin(), answer.end(), less<char>());
    
    return answer == "" ? "N" : answer;
}
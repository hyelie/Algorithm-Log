//  Runtime 0 ms Beats 100%
// Memory 6.2 MB Beats 81.54%

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{') stk.push(c);
            else{
                if(stk.empty()) return false;
                if(c == ')'){
                    if(stk.top() == '(') stk.pop();
                    else return false;
                }
                else if(c == ']'){
                    if(stk.top() == '[') stk.pop();
                    else return false;
                }
                else if(c == '}'){
                    if(stk.top() == '{') stk.pop();
                    else return false;
                }
            }
        }
        return stk.empty();
    }
};
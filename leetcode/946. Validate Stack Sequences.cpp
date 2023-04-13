class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        vector<bool> isPushed(len+1, false);
        stack<int> stk;
        for(int i = 0, pushedidx = 0; i<len; i++){
            if(isPushed[popped[i]] == false){
                while(pushedidx < len){
                    stk.push(pushed[pushedidx]);
                    isPushed[pushed[pushedidx]] = true;
                    pushedidx++;
                    if(stk.top() == popped[i]) break;
                }
            }
            if(isPushed[popped[i]] == true && !stk.empty() && stk.top() == popped[i]){
                stk.pop();
            }
            else return false;
        }
        return true;
    }
};

/*
programmesr에서 풀어 본 stack simluation 문제

popped에서 unpushed인 경우, 그거까지 push
 - push 할 때 보이는 것들 전부 다 pushed로 마킹
pushed인 경우, stack top과 다르다면 return false. 같으면 pop 이후 계속
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;

        for(int v : pushed){
            stk.push(v);
            while(!stk.empty() && stk.top() == popped[i]){
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};
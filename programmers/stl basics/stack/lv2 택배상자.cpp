#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int ordersize = order.size();
    int curNumber = 1;
    int answer = 0;
    stack<int> stk;
    for(int i = 0; i<ordersize; i++){
        while(order[i] >= curNumber){
            stk.push(curNumber);
            curNumber++;
        }
        if(!stk.empty() && order[i] == stk.top()){
            answer++;
            stk.pop();
        }
        else break; // 실수 : 종료 조건 명시하지 않음.
    }
    
    return answer;
}

/*
order[i]가 main container index보다 크거나 같은 경우 -> 빼서 sub에 넣어야 함. sub는 stack임.
최대한 넣을 수 있을 만큼 넣고, stack top이 order[i]와 같은 경우 -> pop하고 다음 order 보면 됨.
못 뽑는다면 종료.
*/
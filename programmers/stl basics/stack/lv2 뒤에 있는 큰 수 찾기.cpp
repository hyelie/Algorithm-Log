#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(vector<int> numbers) {
    stack<pii> stk; // .first : index, .second : value
    vector<int> answer(numbers.size(), -1);
    for(int i = 0; i<numbers.size(); i++){
        while(!stk.empty() && stk.top().second < numbers[i]){
            answer[stk.top().first] = numbers[i];
            stk.pop();
        }
        stk.push({i, numbers[i]});
    }
    
    return answer;
}

// 백준의 오큰수
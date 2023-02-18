#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> count(26, -1);
    vector<int> answer(s.length());
    
    for(int i = 0; i<s.length(); i++){
        answer[i] = count[s[i] - 'a'];
        if(answer[i] != -1) answer[i] = i - answer[i];
        count[s[i] - 'a'] = i;   
    }
    
    return answer;
}
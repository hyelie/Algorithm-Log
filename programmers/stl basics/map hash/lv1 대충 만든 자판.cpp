#include <string>
#include <vector>
#include <map>
#include <climits>

using namespace std;

map<char, int> m; // m[c] : c에 해당하는 글자를 몇 번 눌러야 나오는지 min값

vector<int> solution(vector<string> keymap, vector<string> targets) {
    for(char c = 'A'; c <= 'Z'; c++){
        m[c] = INT_MAX;
    }
    for(string s : keymap){
        for(int i = 0; i<s.length(); i++){
            m[s[i]] = min(i+1, m[s[i]]);
        }
    }
    
    vector<int> answer;
    for(string s : targets){
        int count = 0;
        for(char c : s){
            if(m[c] == INT_MAX){
                count = -1;
                break;
            }
            count += m[c];
        }
        answer.push_back(count);
    }
    return answer;
}
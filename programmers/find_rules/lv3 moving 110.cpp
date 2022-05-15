// 110 옮기기

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solve(string s){
    int cnt= 0;
    for(int i = 0; i<s.length()-2; i++){
        if(s.length() < 3) break;
        if(s.length() >= i+3){
            string temp = s.substr(i, 3);
            if(temp == "110"){
                cnt++;
                s.replace(i, 3, "");
                i = max(-1, i-3);
            }
        }
    }
    int zero_idx = -1;
    for(zero_idx = s.length()-1; zero_idx >= 0; zero_idx--){
        if(s[zero_idx] == '0') break;
    }
    string target = "";
    while(cnt--) target += "110";
    s.insert(zero_idx+1, target);
    
    return s;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(string& each_s : s){
        answer.push_back(solve(each_s));
    }
    return answer;
}

// 110은 1보다는 앞에 와야 하고, 0보다는 뒤에 와야 함
// 모든 110을 찾아서 제일 뒤에 있는 0 뒤에 붙이면 될듯?
// 1 110 0 -> 0이 사전순 앞임 -> 1 0 110
// 1 110 1 -> 0이 1보다 앞 -> 110 1 1
// 0 110 0 -> 0이 1보다 앞 -> 0 0 110
// 0 110 1 -> 그대로
// 앞자리가 없는 경우 0으로 생각하면 됨
// 뒷자리가 없는 경우(끝인 경우) 1로 생각하면 됨
// -> 앞자리에 0, 뒷자리에 1 넣고 하면 될 듯?

// 110 뒤에 연속된 0이 있는 경우 -> 110을 제일 뒤로 옮김
// 110 앞에 연속된 1이 있는 경우 -> 110을 제일 앞으로 옮김

// 001101101
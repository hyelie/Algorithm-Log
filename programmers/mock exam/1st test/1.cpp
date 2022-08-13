#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    vector<int> xcnt(10, 0), ycnt(10, 0);
    for(char c : X){
        xcnt[c-'0']++;
    }
    for(char c : Y){
        ycnt[c-'0']++;
    }
    string answer = "";
    for(int i = 9; i>=0; i--){
        int value = min(xcnt[i], ycnt[i]);
        if(i == 0 && answer == ""){
            if(value >= 1) answer += to_string(0);
        }
        else{
            for(int v = 0; v<value; v++){
                answer += to_string(i);
            }
        }
    }
    return answer == "" ? "-1" : answer;
}
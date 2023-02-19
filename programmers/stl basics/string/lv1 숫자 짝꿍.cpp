#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    vector<int> numberCountX(10, 0), numberCountY(10, 0);
    
    for(char c : X) numberCountX[c - '0']++;
    for(char c : Y) numberCountY[c - '0']++;
    
    string answer = "";
    for(int i = 9; i>=0; i--){
        int minValue = min(numberCountX[i], numberCountY[i]);
        for(int j = 0; j<minValue; j++){
            answer += to_string(i);
        }
    }
    
    // 예외처리 : 0000일 때
    if(answer == "") answer = "-1";
    if(answer[0] == '0' && answer[answer.length()-1] == '0') answer = "0";
    
    return answer;
}

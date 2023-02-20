#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    vector<string> ables = {"aya", "ye", "woo", "ma"};
    
    int answer = 0;
    
    for(string str : babbling){
        /*
        I'll replace all [ables] word to number
        */
        string replacedString = "";
        for(int i = 0; i<str.length(); i++){
            bool isReplaced = false;
            for(int ableIdx = 0; ableIdx < ables.size(); ableIdx++){
                if(str.substr(i, ables[ableIdx].length()) == ables[ableIdx]){
                    replacedString += to_string(ableIdx);   
                    isReplaced = true;
                    i += ables[ableIdx].length() - 1;
                    break;
                }
            }
            if(!isReplaced) replacedString += str[i];
        }

        cout<<replacedString<<endl;
        bool canPronounce = true;
        for(int i = 1; i< replacedString.size(); i++){
            if(replacedString[i-1] == replacedString[i]){
                canPronounce = false;
                break;
            }
            if('a' <= replacedString[i] && replacedString[i] <= 'z'){
                canPronounce = false;
                break;
            }
        }
        if(canPronounce) answer++;
    }
    
    return answer;
}

int main(){
    solution({"aya", "yee", "u", "maa"});
}
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
struct chardata{
    int start, end, num;
    char c;
};

bool isAllUpper(string& sentence, int startidx, int endidx){
    for(int i = startidx; i<=endidx; i++){
        if(!isupper(sentence[i])) return false;
    }
    return true;
}

string getRule1(string& sentence, chardata& cd){
    if(cd.end + 1 >= sentence.size() || cd.start - 1 < 0) return "invalid";
    for(int j = cd.start; j<=cd.end; j += 2){
        if(isupper(sentence[j]) || sentence[j] != cd.c) return "invalid";
    }
    string result = "";
    for(int j = cd.start-1; j<=cd.end+1; j += 2){
        if(islower(sentence[j])) return "invalid";
        result += sentence.substr(j, 1);
    }
    if(result == "") return "invalid";
    return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    
    unordered_map<char, chardata> m;
    for(int i = 0; i<sentence.size(); i++){
        char c = sentence[i];
        if(isupper(c)) continue;
        if(m.find(c) == m.end()){
            chardata cd; cd.start = cd.end = i; cd.num = 1; cd.c = c;
            m[c] = cd;
        }
        else{
            m[c].end = i; m[c].num++;
        }
    }
    
    vector<string> answer_v;
    map<char, int> used;
    for(int i = 0; i<sentence.size(); i++){
        if(isupper(sentence[i])){
            if(i+1 < sentence.size() && islower(sentence[i+1]) && m[sentence[i+1]].num != 2){
                chardata cd = m[sentence[i+1]];
                if(used[cd.c] == 1) return "invalid";
                used[cd.c] = 1;
                string result = getRule1(sentence, cd);
                if(result == "invalid") return result;
                answer_v.push_back(result);
                i = cd.end+1;
            }
            else{
                answer_v.push_back(sentence.substr(i, 1));
            }
        }
        else{
            chardata cd = m[sentence[i]];
            if(used[cd.c] == 1) return "invalid";
            used[cd.c] = 1;
            if(cd.num != 2) return "invalid";
            if(isAllUpper(sentence, cd.start+1, cd.end-1)){
                string result = sentence.substr(cd.start+1, cd.end - cd.start - 1);
                if(result == "") return "invalid";
                answer_v.push_back(result);
            } else{
                if(i+2 < sentence.size() && !islower(sentence[i+2])) return "invalid";
                chardata nestedcd = m[sentence[i+2]];
                if(used[nestedcd.c] == 1) return "invalid";
                used[nestedcd.c] = 1;
                string result = getRule1(sentence, nestedcd);
                if(result == "invalid") return result;
                answer_v.push_back(result);
            }
            i = cd.end;
        }
    }
    
    
    
    string answer = "";
    for(string s : answer_v){
        answer += s + " ";
    }
    return answer.substr(0, answer.length()-1);
}
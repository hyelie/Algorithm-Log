#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

struct cmp{
    bool operator()(const string &a, const string &b) const{
        if(a.length() == b.length()){
            return a < b;
        }
        else return a.length() < b.length();
    }
};

// string s를 발음할 수 있는지
// 발음할 수 있는 단어를 s에서 지워나갈 것임
bool canPronounce(string s){
    // 1) 길이순, 2) 알파벳순 정렬
    set<string, cmp> ables = {"aya", "ye", "woo", "ma"};
    
    // ables 순회하며 s를 더 없애지 못할 때까지 반복
    while(1){
        // s 길이가 0이면 더 없애지 못함 - true
        if(s.length() == 0) return true;
        
        bool matched = false; // 이번 순회에서 단어 하나를 없앴는지
        
        for(string able : ables){
            if(s.length() < able.length()) break; // 길이가 짧으면 검사 못함, break 이후 다시 처음부터 검사
            
        	if(s.substr(0, able.length()) == able){ // able을 발음가능한지 검사
				if(s.length() == able.length()) return true;
                s = s.substr(able.length());    // 해당 단어 없애고 set에서도 삭제
                ables.erase(able);
                matched = true;
            }
        }
        
        if(!matched) return false;
    }
    return true;
}


int solution(vector<string> babbling) {
    int answer = 0;
    for(string s : babbling){
        if(canPronounce(s)) answer++;
    }
    
    return answer;
}
// 신규 아이디 추천

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string new_id) {
    vector<char> vs(new_id.begin(), new_id.end());
    vector<char>::iterator iter, next_iter;    
    for(iter = vs.begin(); iter != vs.end();){
        *iter = tolower(*iter); // 1단계
        if(!(isalpha(*iter) || isdigit(*iter) || *iter == '-' || *iter == '_' || *iter == '.')){
            iter = vs.erase(iter);
        } // 2단계
        else iter++;
    }

    for(iter = vs.begin(); iter != vs.end(); iter++){
        if(*iter == '.'){
            next_iter = iter + 1;
            while(next_iter != vs.end() && *next_iter == '.'){
                next_iter = vs.erase(next_iter);
            }
        }
    } // 3단계
    
    iter = vs.begin();
    if(*iter == '.') vs.erase(iter);
    iter = vs.end()-1;
    if(*iter == '.') vs.erase(iter);
    // 4단계
    
    if(vs.empty()) vs.push_back('a'); // 5단계
    
    if(vs.size() > 15)
        vs.erase(vs.begin() + 15, vs.end());
    iter = vs.end()-1;
    if(*iter == '.') vs.erase(iter); // 6단계
    
    /*if(vs.size()<=2){
        char c = vs[vs.size()-1];
        while(vs.size()!=3){
            vs.push_back(c);
        }
    }*/
    while(vs.size() < 3){
        vs.push_back(*(vs.end()-1));
    }
    
    string answer = "";
    for(char c : vs){
        answer += c;
    }
    
    return answer;
}


/*

3 <= length <= 15
소문자, 숫자, -, _, . 5종류만 사용할 수 있으며
    .는 연속으로 불가능, 처음과 끝에 불가능 함.

*/
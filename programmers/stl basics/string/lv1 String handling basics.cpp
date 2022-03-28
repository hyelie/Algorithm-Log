// 문자열 다루기 기본

#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
    for(char c : s){
        if(!isdigit(c)) return false;
    }
    return (s.length() == 4 || s.length() == 6) ? true : false;
}
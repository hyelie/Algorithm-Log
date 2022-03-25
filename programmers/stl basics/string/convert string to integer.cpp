#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int is_positive, answer=0;
    string subs = s;
    is_positive = s[0]=='-' ? -1 : 1;
    
    if(s[0] == '+' || s[0] == '-'){
        subs = s.substr(1, s.length());
    }
    answer = stoi(subs) * is_positive;

    return answer;
}
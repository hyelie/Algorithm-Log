// 가운데 글자 가져오기

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int s_length = s.length();
    
    return (s_length & 1) ? s.substr(s_length/2, 1) : s.substr(s_length/2-1, 2);
    
}
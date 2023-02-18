#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int plen = p.length(), tlen = t.length();
    
    for(int i = 0; i<tlen - plen + 1; i++){
        if(t.substr(i, plen) <= p) answer++;
    }
    
    return answer;
}

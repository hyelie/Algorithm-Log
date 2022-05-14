// 가장 긴 팰린드롬

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = 1, len = s.length();
    
    // i : string 중간점
    for(int i = 1; i<len-1; i++){
        // palin이 홀수
        int maxlen = min(i, len-i-1);
        for(int ilen = 1; ilen<=maxlen; ilen++){
            if(s[i - ilen] != s[i + ilen]){
                break;
            }
            answer = max(answer, 2*ilen + 1);
        }
        // palin이 짝수
        for(int ilen = 0; ilen <= maxlen+1; ilen++){
            if(s[i-ilen] != s[i + ilen-1]){ // ilen이 0이면 i랑 그 앞에것 비교
                break;
            }
            answer = max(answer, 2*ilen);
        }
    }
   
    
    return answer;
}
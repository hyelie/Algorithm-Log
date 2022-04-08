// 압축

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    // 단계 1
    map<string, int> dict;
    vector<string> alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    int dict_idx = 1;
    for(dict_idx = 1; dict_idx < 27; dict_idx++)
        dict[alphabet[dict_idx-1]] = dict_idx;
    
    vector<int> answer;
    int maxlen = 1, msg_length = msg.length();
    for(int i = 0; i<msg_length;){
        if(i + maxlen >= msg_length) maxlen = msg_length - i;
        // 단계 2
        for(int len = maxlen; len >= 1; len--){
            string substring = msg.substr(i, len); // 가장 긴 문자열 
            
            // 단계 3
            if(dict[substring] != 0){
                answer.push_back(dict[substring]);
                
                // 단계 4
                if(i + len < msg_length){
                    maxlen = max(maxlen, len + 1);
                    dict[msg.substr(i, len + 1)] = dict_idx++;
                }
                
                i += len;
                break;
            }
        }
    }
    
    
    return answer;
}
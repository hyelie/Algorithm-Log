// 문자열 압축

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(string s) {
    int length = s.length(), min_value = 9999999;
    
    // cl : 압축 단위(compress length). ceil을 쓴 이유는 문자열 길이가 1일 수 있기 때문임.
    for(int cl = 1; cl<=ceil((double)length/2); cl++){
        string compressed_s = "";
        for(int i = 0; i<length;){
            int repeat_num = 1;
            string unit_string = "";
            if(i + cl <= length){ // 문자열 검사를 할 수 있는 경우
                unit_string = s.substr(i, cl);
                i += cl;
                while(i + cl <= length){
                    string next_string = s.substr(i, cl);
                    if(unit_string != next_string) break;
                    repeat_num++;
                    i += cl;
                }
            } else { // 문자열 마지막 부분인 경우
                unit_string = s.substr(i, length-i);
                i += cl;
            }

            if(repeat_num > 1){ // 중복문자열이 존재하는 경우
                compressed_s += to_string(repeat_num) + unit_string;
            } else{ // 존재하지 않는 경우
                compressed_s += unit_string;
            }
        }
        min_value = min_value > compressed_s.length()? compressed_s.length() : min_value;
    }
    
    return min_value;
}
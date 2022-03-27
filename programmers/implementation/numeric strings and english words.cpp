// 숫자 문자열과 영단어

#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(string s) {
    vector<string> table = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    string number_string = "";
    int length = s.length();
    for(int i = 0; i<length;){
        if(isdigit(s[i])){
            number_string += s[i];
            i++;
        } 
        else{
            string temp = "";
            int idx;
            vector<string>::iterator iter;
            while(i < length && !isdigit(s[i])){
                temp += s[i];
                i++;
                iter = find(table.begin(), table.end(), temp);
                if(iter != table.end()){
                    number_string += to_string(iter - table.begin());
                    break;
                }
            }
        }
    }
    
    return stoi(number_string);
}
// 시저 암호

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int charType(char c){
    if('A' <= c && c <= 'Z') return 2;
    else if('a' <= c && c <= 'z') return 1;
    else return 0;
}

string solution(string s, int n) {
    int push_value = n%26, length = s.size();
    
    for(int i = 0; i<length; i++){
        
        if(s[i] == ' ')continue;
        if(isalpha(s[i]) != isalpha(s[i] + push_value)){
        //if(charType((int)s[i]) != charType(s[i] + push_value)){
            s[i] = s[i] + push_value - 26;
        }
        else{
            s[i] += push_value;
        }       

    
    }
    
    return s;
}
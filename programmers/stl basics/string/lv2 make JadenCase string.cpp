// JadenCase 문자열 만들기

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    bool is_after_space = true;
    int length = s.length();
    for(int i = 0; i<length; i++){
        if(is_after_space){
            s[i] = toupper(s[i]);
            is_after_space = false;
        } else{
            s[i] = tolower(s[i]);
        }
        if(s[i] == ' '){
            is_after_space = true;
        }
    }
    return s;
}

/*
string solution(string s) {
   
    for(int i = 0; i<s.size(); i++){
        s[i] = tolower(s[i]);
    }
    
    s[0] = toupper(s[0]);
    for(int i = 1; i<s.size(); i++){
        if(s[i] == ' '){
            s[i+1] = toupper(s[i+1]);
        }
    }
    
    return s;
}*/
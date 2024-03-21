#include <string>
#include <vector>
#include <iostream>

using namespace std;

string remove_unallowed(string &input){
    string result = "";
    for(char c : input){
        if(isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.') result += c;
    }
    return result;
}

string remove_consecutive_dot(string &input){
    string result = "";
    for(int i = 0; i<input.size();){
        result += input[i];
        if(input[i] == '.') while(i < input.size() && input[i] == '.') i++;
        else i++;
    }
    return result;
}

string solution(string new_id) {
    // 1
    for(char &c : new_id){
        if(isalpha(c)) c = tolower(c);
    }
    
    // 2
    string removed_id = remove_unallowed(new_id);
    
    // 3
    string one_dot_id = remove_consecutive_dot(removed_id);
    
    // 4
    if(one_dot_id.size() > 0 && one_dot_id[0] == '.') one_dot_id = one_dot_id.substr(1);
    if(one_dot_id.size() > 0 && one_dot_id[one_dot_id.length()-1] == '.') one_dot_id = one_dot_id.substr(0, one_dot_id.length()-1);
    
    // 5
    if(one_dot_id.size() == 0) one_dot_id = "a";
    
    // 6
    string result = one_dot_id;
    if(result.size() >= 16){
        result = result.substr(0, 15);
        if(result[14] == '.') result = result.substr(0, 14);
    }
    
    // 7
    while(result.length() < 3){
        result += result[result.length()-1];
    }
    
    return result;
}
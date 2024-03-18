#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toBinary(int n){
    if(n == 0) return "0";
    
    string digits = "01";
    string result = "";
    while(n){
        result = digits[n % 2] + result;
        n /= 2;
    }
    return result;
}

string fillZeros(string str, int n){
    if(str.length() == n) return str;
    while(1){
        if(str.length() == n) break;
        str = "0" + str;
    }
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    int len = arr1.size();
    for(int i = 0; i<len; i++){
        arr1[i] = arr1[i] | arr2[i];
    }
    
    vector<string> answer;
    for(int elem : arr1){
        string str = fillZeros(toBinary(elem), n);
        for(char& c : str){
            if(c == '0') c = ' ';
            else c = '#';
        }
        answer.push_back(str);
    }
    return answer;
}
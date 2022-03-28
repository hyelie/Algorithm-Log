#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 2진수를 받아서 문자열 변환 및 공백 처리한 후 리턴해 줌.
string to_binary(int input, int size){
    string result = "", temp;
    while(input!=0){
        (input%2) ? temp = "#" : temp = " ";
        result = temp + result;
        input /= 2;
    }
    while(result.length() < size) result = " " + result;
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    string s1, s2, result;
    
    for(int i = 0; i<n; i++){
        /*s1 = to_binary(arr1[i], n);
        s2 = to_binary(arr2[i], n);
        result = s1;
        for(int j = 0; j<n; j++){
            if(s2[j] == '#') result[j] = '#';
        }
        answer[i] = result;*/
        
        // | 연산자를 이용해 한 번에 처리할 수 있다....
        
        answer[i] = to_binary(arr1[i]|arr2[i], n);
    }
    
    
    return answer;
}
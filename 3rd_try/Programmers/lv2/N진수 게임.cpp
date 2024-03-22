#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_notation(int number, int notation){
    if(number == 0) return "0";
    string digits = "0123456789ABCDEF";
    string result = "";
    while(number){
        result = digits[number % notation] + result;
        number /= notation;
    }
    return result;
}

// n : 진법
// t : 미리 구할 수 숫자 개수
// m : 참가 인원
// p : 순서
string solution(int n, int t, int m, int p) {
    string total = "";
    int num = 0;
    while(total.length() <= m * t){
        total += to_notation(num, n);
        num++;
    }
    
    string answer = "";
    for(int i = 0; i<t; i++){
        answer += total[i * m + p-1];   
    }
    return answer;
}

/*
개꿀팁

*/
// n진수 게임

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char digitToNotation(int number){
    if(number < 10) return number + '0';
    else{
        return 'A' + (number - 10);
    }
}

// number를 n진법으로 변환해 string으로 return
string toNotation(int number, int notation){
    if(number == 0) return "0";
    char digit[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                      'A', 'B', 'C', 'D', 'E', 'F'};
    string result = "";
    while(number){
        result = digit[number % notation] + result;
        number /= notation;
    }
    return result;
}

// n : 진법
// t : 미리 구할 수 숫자 개수
// m : 참가 인원
// p : 순서
string solution(int n, int t, int m, int p) {
    string answer = "", numberList = "";
    int number = 0;
    
    while(t--){
        while(numberList.length() < m){
            numberList += toNotation(number++, n);
        }
        answer += numberList[p-1];
        numberList.erase(0, m);
    }
    return answer;
}

/*
개꿀팁

*/
// 3진법 뒤집기

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string to_ternary(int n){
    string t = "";
    while(n != 0){
        t.append(to_string(n%3));
        n /= 3;
    }
    reverse(t.begin(), t.end());
    return t;
}

int to_decimal(string t){
    int cnt = 1, length = t.length(), result = 0;
    for(int i = length-1; i>=0; i--){
        result += cnt * (t[i] - '0');
        cnt *= 3;
    }
    return result;
}

int solution(int n) {
    string t = to_ternary(n);
    reverse(t.begin(), t.end());
    return to_decimal(t);
}
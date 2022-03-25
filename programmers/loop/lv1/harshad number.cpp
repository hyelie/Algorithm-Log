#include <string>
#include <vector>
#include <iostream>

using namespace std;

int decompose(int x){
    int digit_sum = 0;
    while(x != 0){
        digit_sum += x%10;
        x /= 10;
    }
    return digit_sum;
}

bool solution(int x) {
    return x % decompose(x) == 0;
}
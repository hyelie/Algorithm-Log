#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



long long solution(long long n) {    
    vector<int> digits;
    while(n != 0){
        digits.push_back(n%10);
        n /= 10;
    }
    
    sort(digits.begin(), digits.end(), less<int>());

    long long answer = 0;
    long long point = 1;
    for(int digit : digits){
        answer += (long long)digit* point;
        point *= 10;
    }
    
    return answer;
}
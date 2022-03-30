// 약수의 개수와 덧셈

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// 짝수면 true
bool number_of_factors(int n){
    set<int> s;
    for(int i = 1; i * i <= n; i++){
        if(n%i == 0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    return (s.size() % 2) == 0;
}

int solution(int left, int right) {

    int answer = 0;
    for(int i = left; i<=right; i++){
        if(number_of_factors(i)) answer += i;
        else answer -= i;
    }
    
    return answer;
}
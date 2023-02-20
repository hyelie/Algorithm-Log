#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    vector<int> count(number+1, 1); // 모든 수의 공통약수 : 1
    
    for(int i = 2; i<=number; i++){
        for(int j = i; j<=number; j+=i){
            count[j]++;
        }
    }
    
    int answer = 0;
    for(int i = 1; i<=number; i++){
        answer += count[i] > limit ? power : count[i];
    }
    return answer;
}
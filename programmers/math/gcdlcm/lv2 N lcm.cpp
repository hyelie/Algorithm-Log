// N개의 최소공배수

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    int temp;
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int size = arr.size();
    
    long long answer = 1;
    for(int i = 0; i<size; i++){
        answer = lcm(answer, arr[i]);
    }
    return answer;
}
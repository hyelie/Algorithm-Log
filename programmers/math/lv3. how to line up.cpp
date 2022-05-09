// 줄 서는 방법

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

vector<int> solution(int n, long long k) {
    vector<ll> factorial(21); factorial[0] = factorial[1] = 1;
    for(int i = 2; i<=20; i++){
        factorial[i] = factorial[i-1] * i;
    }
    
    vector<int> people(n);
    for(int i = 1; i<=n; i++){
        people[i-1] = i;
    }
    
    vector<int> answer;
    k--; // k번째 방법 : index로 바꾸면 k-1임. 이걸 안해줬음!
    for(int i = 1; i<n; i++){
        int idx = k / factorial[n-i];
        k = k % factorial[n-i];
        answer.push_back(people[idx]); people.erase(people.begin() + idx);
    }
    answer.push_back(people[0]);

    
    return answer;
}
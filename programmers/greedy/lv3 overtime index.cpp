// 야근 지수

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    
    for(int i : works) pq.push(i);
    
    while(n > 0 && !pq.empty()){
        ll max_value = pq.top(); pq.pop(); n--;
        if(max_value == 1) continue;
        pq.push(max_value-1);
    }
    
    
    long long answer = 0; ll pqtop;
    while(!pq.empty()){
        pqtop = pq.top(); pq.pop();
        answer += pqtop * pqtop;
    }
    
    return answer;
}
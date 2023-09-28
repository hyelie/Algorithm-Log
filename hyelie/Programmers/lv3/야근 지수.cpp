#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
pq 쓰는 문제. 제일 큰 것을 1 줄이는게 제일 좋다.
n은 
*/

typedef long long ll;

long long solution(int n, vector<int> works) {
    priority_queue<int, vector<int>, less<int>> pq;
    for(int work : works) pq.push(work);
    
    while(1){
        if(n == 0 || pq.empty()) break;
        int t = pq.top(); pq.pop();
        if(t != 1) pq.push(t-1);
        n--;
    }
    
    long long answer = 0;
    while(!pq.empty()){
        int t = pq.top(); pq.pop();
        answer += (ll) t * (ll) t;
    }
    return answer;
}
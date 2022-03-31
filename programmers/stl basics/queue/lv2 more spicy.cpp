#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef long long ll;

int solution(vector<int> scoville, int K) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    
    for(int elem : scoville){
        pq.push((ll)elem);
    }
    
    int answer = 0;
    ll f, s;
    while(pq.size() > 1 && pq.top() < K){
        f = pq.top(); pq.pop();
        s = pq.top(); pq.pop();
        pq.push(f + s * 2);
        answer++;
    }
    return pq.top() >= K ? answer : -1;

}

// length = 1백만 -> nlogn
// pq.size()는 항상 1보다 크다는 것을 증명할 수 있다. 그러므로 while문의 pq.size() > 1일 때 계속 돌린다.

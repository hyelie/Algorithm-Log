#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
greedy같지? 제일 작은 것 2개를 합쳐야 한다.
a, b, c, ...라고 오름차순 정렬했을 때
a, b를 합치는 경우 -> a+b, a+b, c, ...가 된다.
a, c를 합치는 경우 a+c, b, a+c, ...가 된다.
둘의 차이는
a+b+a+b+c+...
a+c+b+a+c+...
후항에서 전항을 빼면 c-b인데, 이는 무조건 양수. 따라서 최소인 것을 고르지 않으면 sum이 최소가 되지 않는다.
*/

int solution(vector<int> ability, int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int a : ability) pq.push(a);
    
    while(n--){
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        pq.push(first + second);
        pq.push(first + second);
    }
    
    int answer = 0;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    return answer;
}
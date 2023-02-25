#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int n = queue1.size();
    
    ll q1sum = 0, q2sum = 0;
    queue<int> q1, q2;
    for(int i = 0; i<n; i++){
        q1.push(queue1[i]); q1sum += queue1[i];
        q2.push(queue2[i]); q2sum += queue2[i];
    }
    
    int answer = 0;
    for(int i = 0; i<4*n; i++, answer++){
        if(q1sum == q2sum) return answer;
        if(q1sum > q2sum){
            q1sum -= q1.front(); q2sum += q1.front();
            q2.push(q1.front()); q1.pop();
        }
        else{ // q1sum < q2sum
            q2sum -= q2.front(); q1sum += q2.front();
            q1.push(q2.front()); q2.pop();
        }
    }
    
    return -1;
}

#include <string>
#include <queue>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    ll q1_size = queue1.size(), q2_size = queue2.size();
    ll limit = q1_size + q2_size;
    
    // init
    ll q1_sum = 0;
    queue<int> q1;
    for(int i = 0; i<q1_size; i++){
        q1_sum += queue1[i];
        q1.push(queue1[i]);
    }
    
    ll q2_sum = 0;
    queue<int> q2;
    for(int i = 0; i<q2_size; i++){
        q2_sum += queue2[i];
        q2.push(queue2[i]);
    }
    
    // cal
    int answer = 0;
    limit *= 2; // *** 실수한 곳
    while(limit--){
        if(q1_sum == q2_sum) return answer;
        
        if(q1_sum > q2_sum){
            ll front = q1.front(); q1.pop();
            q1_sum -= front;
            q2_sum += front; q2.push(front);
        }
        else{ // q1_sum < q2_sum
            ll front = q2.front(); q2.pop();
            q2_sum -= front;
            q1_sum += front; q1.push(front);
        }
        
        answer++;
    }
    
    return -1;
}
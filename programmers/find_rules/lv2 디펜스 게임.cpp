#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
int solution(int n, int k, vector<int> enemy) {
    priority_queue<ll> pq;
    int i = 0;
    ll sum = 0;
    
    while(1){
        if(i < enemy.size()){
            if(n >= sum + enemy[i]){ // 이번 wave 감당 가능하면 넣음
                sum += enemy[i];
                pq.push(enemy[i]);
                i++;
            }
            else if(k > 0){ // 이번 wave 감당 불가면 무적건 써야 함. 없으면 불가
                sum += enemy[i];
                pq.push(enemy[i]);
                i++;
                k--;
                sum -= pq.top();
                pq.pop();    
            }
            else break;
        }
        else break;
    }
    
    return i;
}
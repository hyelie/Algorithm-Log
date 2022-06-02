// 금과 은 운반하기

#include <string>
#include <vector>
#include <limits.h>

typedef long long ll;
using namespace std;

bool isMoveable(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, ll totaltime){
    // 시간이 totaltime
    ll size = g.size();
    ll max_gold = 0, max_silver = 0, max_sum = 0;
    for(int i = 0; i<size; i++) {        
        ll num_move;
        if(totaltime < (ll)t[i]) continue; // 1번도 못옮기는 경우
        else{
            num_move = (totaltime - t[i]) / (2 * t[i]) + 1; // 여러 번 옮길 수 있는 횟수
        }
        ll move_amount = num_move * w[i];
        max_gold += min((ll)g[i], move_amount);
        max_silver += min((ll)s[i], move_amount);
        max_sum += min((ll)g[i] + s[i], move_amount);
    }
    if(max_gold >= a && max_silver >= b && max_sum >= a+b) return true;
    else return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    ll start = 0, end = 1e17, mid;
    
    while(start < end){
        mid = (start + end) / 2;
        if(isMoveable(a, b, g, s, w, t, mid)){ // mid가 옮길 수 있다면
            end = mid;
        } else
            start = mid+1;
    }
    return end;
}
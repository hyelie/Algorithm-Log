#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> times;

// t시간동안 심사할 수 있는 인원 수
ll calculateNumPass(ll t){
    ll num_pass = 0;
    for(int time : times){
        num_pass += ((ll) t / time);
    }
    return num_pass;
}

long long solution(int n, vector<int> t) {
    ll start = 0, end = 1e18;
    times = t;
    
    while(start < end){
        ll mid = (start + end) / 2;
        ll num_pass = calculateNumPass(mid);
        if(num_pass >= n){ // 시간을 더 줄일 수 있을 때
            end = mid;
        }
        else{ // 시간을 늘려야 할 때
            start = mid + 1;
        }
    }
    
    return start;
}
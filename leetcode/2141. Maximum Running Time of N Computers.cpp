// Runtime 160 ms Beats 95.32%
// Memory 55.8 MB Beats 71.58%

typedef long long ll;

class Solution {
public:
    // time 안에 batteries 사용해서 n개의 computer 동시 구동 가능?
    // 검사는 O(n)으로 해야함
    bool possible(int n, vector<int>& batteries, ll time){
        ll sum = 0;
        for(int b : batteries){
            if(b > time) sum += time;
            else sum += b;
        }
        // 각 battery들의 합을 더하는데, 최대 time만큼 더함
        // n * time = battery 합이 
        if(sum >= n*time) return true;
        else return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll start = 1, end = 1e14+1, mid;
        while(start < end){
            ll mid = (start + end) / 2;
            if(!possible(n, batteries, mid)) end = mid; // not possible then 시간 줄여야 함
            else start = mid + 1;
        }
        return end-1;
    }
};
// Runtime 225 ms Beats 98.69%
// Memory 94.5 MB Beats 33.40%

typedef long long ll;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll start = 0, end = LLONG_MAX, mid = -1;
        while(start < end){
            mid = (start + end) / 2;

            ll cnt = 0; // number of trips
            for(int t : time){
                cnt += mid / t;
                if(cnt >= totalTrips) break;
            }

            if(cnt >= totalTrips){
                end = mid;
            }
            else start = mid + 1;
        }
        return end;
    }
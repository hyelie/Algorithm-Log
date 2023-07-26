// Runtime 473 ms Beats 14.39%
// Memory 101.5 MB Beats 67.19%
// -> 12, 13번줄 대신 ceil() 사용 시
// Runtime 327 ms Beats 64.60%
// Memory 101.5 MB Beats 67.19%

class Solution {
public:
    bool available(vector<int>& dist, int speed, double hour){
        double sum = 0;
        for(int i = 0; i<dist.size()-1; i++){
            // sum += (dist[i] / speed);
            // if(dist[i] % speed != 0) sum += 1;
            sum += ceil((double)dist[i] / speed);
        }
        // 마지막 element만이 hour의 소수점에 관여한다.
        int last = dist[dist.size()-1];
        sum += (double)last / speed;

        if(sum <= hour) return true;
        else return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= n-1) return -1;

        int start = 1, end = 10000000, mid;
        while(start < end){
            mid = (start + end) / 2;
            bool isAvailable = available(dist, mid, hour);
            if(isAvailable) end = mid;
            else start = mid + 1;
        }

        return end;
    }
};

/*
hour : 도착해야 하는 시간
dist[i] : ith train을 탔을 때 거리

출력값 : 속도의 최소값, 불가능 시 -1

binary search인가?

1. 불가능한 조건은 언제 나올까
아무리 큰 speed로 dist[i]를 나누어도 올림한다. 즉, dist[i] 하나당 최소 1시간은 필요하다는 의미이다.
따라서, hour 안에 도착하기 위해서는 n-1보다 큰 시간이 필요하다.
hour <= n-1인 경우 불가능하다는 의미이다.
hour가 n-1보다 epsilon만큼 큰 경우는 speed를 매우 크게 설정해 달성할 수는 있다.

2. 가능한 조건을 어떻게 추릴까
정답이 10^7을 초과하지 않는다. -> 최대 10^7로 잡으면 된다는 것 같다.
binary search가 맞는 듯.
*/
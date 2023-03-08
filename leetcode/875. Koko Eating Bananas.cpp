// Runtime 36 ms Beats 97.14%
// Memory 19 MB Beats 45.12%

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 1000000001, mid, hsum;
        while(start < end){
            mid = (start + end) / 2;

            hsum = 0; // 다 먹는데 걸리는 시간 
            for(int i : piles){
                hsum += i/mid + (i%mid != 0);
                if(hsum > h) break;
            }

            if(hsum <= h) end = mid;
            else start = mid + 1;
        }
        return end;
    }
};
/*
상한?
max of piles
이것보다 더 커도 hsum을 더 줄일 수 없다


*/
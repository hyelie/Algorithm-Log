// 징검다리 건너기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPassable(int num, vector<int>& stones, int k){
    int cnt = 0;
    for(int i = 0; i<stones.size(); i++){
        if(stones[i] - num <= 0) cnt++;
        else cnt = 0;
        if(cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int size = stones.size();
    
    int l = 1, r = 200000000, mid;
    
    // binary search lower bound
    while(l < r){
        mid = (l+r)/2;
        if(!isPassable(mid, stones, k)) r = mid;
        else l = mid+1;
    }
    return r;
}

/*

어떤 idx i에 대해
i+1, i+2, ... , i+k-1이 모두 i보다 작거나 같다면
i, i+1, ... , i+k-1 중 max값이 그것임.

*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// n명이 stones 건너는 경우 (k 주어짐)
// n명이 건넜을 때 n+1명째가 건널 수 있는지
bool can_pass(vector<int>& stones, int n, int k){
    int zeros = 0;
    for(int stone : stones){
        if(stone - n <= 0) zeros++;
        else zeros = 0;
        
        cout<<stone<<", "<<zeros<<endl;
        
        if(zeros >= k) return false;
    }
    return true;
}

int ub(vector<int> &stones, int k){ // 
    int start = 0, end = 200000001, mid;
    while(start < end){
        mid = start + (end - start) / 2;
        if(!can_pass(stones, mid, k)) end = mid; // mid는 건너지만, mid+1번째는 못 건너는 최소값.
        else start = mid + 1;
    }
    return end;
}

int solution(vector<int> stones, int k) {
    return ub(stones, k);
}

/*
n명이 건널 수 있다고 생각했을 때
최대 2억명이 건널 수 있음. 
따라서 정상적인 search로 못 찾음
따라서 binary search
*/
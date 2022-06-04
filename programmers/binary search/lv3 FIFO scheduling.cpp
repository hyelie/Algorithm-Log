// 선입 선출 스케줄링

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


bool work(int total_works, int time, vector<int>& cores){
    int num_works = 0;
    for(int c : cores){
        num_works += time/c;
    }
    
    if(total_works <= num_works + cores.size()) return true;
    else return false;
}

int solution(int n, vector<int> cores) {
    if(n < cores.size()) return n;
    
    int time = cores[cores.size()-1] * n;
    int s = 1, e = time, mid;
    
    while(s < e){
        mid = (s + e) / 2;
        if(work(n, mid, cores)){
            e = mid;
        }
        else s = mid+1;
    }
    
    n -= cores.size();
    for(int c : cores){
        n -= (e-1)/c;
    }
    for(int i = 0; i<cores.size(); i++){
        if(e % cores[i] == 0)n--;
        if(n == 0) return i+1;
    }
    
    return 1;
}
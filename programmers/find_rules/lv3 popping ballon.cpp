// 풍선 터트리기

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int MAX = 1000000001;

int solution(vector<int> a) {
    int size = a.size();
    vector<int> l(size), r(size); 
    
    l[0] = MAX; // l[i] : i 왼쪽에 있는 값들의 최솟값
    for(int i = 1; i<size; i++){
        l[i] = min(a[i-1], l[i-1]);
    } 
    
    r[size-1] = MAX;  // r[i] : i 오른쪽에 있는 값들의 최솟값
    for(int i = size-2; i>=0; i--){
        r[i] = min(a[i+1], r[i+1]);
    }
    
    
    int cnt = 0;
    for(int i = 0; i<size; i++){
        //cout<<"l : "<<l[i]<<", r : "<<r[i]<<", c : "<<a[i]<<endl;
        if(l[i] < a[i] && r[i] < a[i]) continue;
        cnt++;
    }
    
    return cnt;
}

// i번째 index에 대해 왼쪽 그룹의 최솟값, 오른쪽 그룹의 최솟값을 알아내는 게 이 문제의 요점 O(n) 안에.
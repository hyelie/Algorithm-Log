// 스타 수열

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

bool cmp(pii &a, pii &b){
    return a.second > b.second;
}

int solution(std::vector<int> a) {
    map<int, int> m;
    int size = a.size();
    for(int i : a) m[i]++;
    
    int answer = 0;
    for(pii p : m){
        int value = p.first;
        if(2 * p.second <= answer) continue;
        int max_len = 0;
        for(int j= 0; j<size-1; j++){
            if(a[j] == a[j+1]) continue; // 수가 같은 경우 - 어차피 스타수열이 될 수 없음
            if(a[j] != value && a[j+1] != value) continue; // 두 수 다 스타수열이 아닌 경우 - 스타수열이 될 수 없음
            j++; max_len += 2;
        }
        answer = max(max_len, answer);
    }
    
    return answer;
}
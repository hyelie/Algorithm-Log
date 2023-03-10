#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii; // .first : starts의 index / .second : starts[i]의 값
bool cmp(pii &a, pii &b){
    return a.second > b.second; // 내림차순 정렬
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> counts(e+1, 1);
    // counts[i].first : 숫자 i
    // counts[i].second : number i가 억억단에서 나온 회수 = 약수 개수 
    
    // 모든 숫자에 대해 그 수의 약수 개수를 구함
    // [1/2 + 1/3 + 1/4 + ... + 1/n] * n = nlogn
    for(int i = 2; i<=e; i++){
        for(int j = i; j<=e; j += i){
            counts[j]++;
        }
    }
    
    /*vector<pii> startWithIndex(starts.size());
    for(int i = 0; i<starts.size(); i++){
        startWithIndex[i] = {i, starts[i]};
    }
    sort(startWithIndex.begin(), startWithIndex.end(), cmp);
    
    // 정답 넣기
    vector<int> answer(starts.size());
    int sidx, i = e; // sidx : starts의 순회 index / i : 숫자 iterator
    pii maxValue = {counts[e], e}; // .first : 숫자 개수, e
    for(sidx = 0; sidx<starts.size(); sidx++){
        for(; i >= startWithIndex[sidx].second; i--){
            if(counts[i] >= maxValue.first){
                maxValue = {counts[i], i};
            }
        }
        answer[startWithIndex[sidx].first] = maxValue.second;
    }*/
    // startWithIndex : 내림차순 되어있음
    
    vector<int> answer(starts.size()), largestCounts(e+1);
    largestCounts[e] = e;
    // answer : 정답 배열, largestCounts[i] : e부터 i까지 제일 많이 등장하는 수
    for(int i = e-1; i>=1; i--){
        if(counts[i] < counts[i+1]){
            counts[i] = counts[i+1];
            largestCounts[i] = largestCounts[i+1];
        }
        else largestCounts[i] = i;
    }
    
    for(int i = 0; i<starts.size(); i++){
        answer[i] = largestCounts[starts[i]];
    }

    
    return answer;
}
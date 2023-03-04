#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<int, int> m; // m[i] : 무게가 i인 사람 명수

// w에 해당하는 배율이 가능한 위치 찾음
typedef pair<int, int> pii;
vector<pii> positions;
vector<int> ables(7);
void setAbles(int w){
    for(int i = 0; i<positions.size(); i++){
        int left = positions[i].first * w;
        if(left % positions[i].second){
            ables[i] = -1;
        }
        else{
            ables[i] = left / positions[i].second;
        }
    }
}

long long solution(vector<int> weights) {
    positions =  {{2, 2}, {2, 3}, {2, 4}, {3, 2}, {3, 4}, {4, 2}, {4, 3}};
    for(int w : weights){
        if(m.find(w) == m.end()) m[w] = 1;
        else m[w]++;
    }
    
    long long answer = 0;
    for(int i : weights){
        setAbles(i);
        for(int a : ables){
            if(a == -1) continue;
            if(m.find(a) != m.end()){
                answer += m[a] - (a == i);
            }
        }
    }
    
    return answer/2;
}
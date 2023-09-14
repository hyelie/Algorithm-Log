#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii; // .first : 시작 지점, .second : 끝 지점. (included)

int solution(int n, vector<int> stations, int w)
{
    int s = stations[0] - w, e = stations[0] + w;
    s = max(s, 1); e = min(e, n);
    pii p = {s, e};
    vector<pii> overlaps(1, p);
    
    // 겹쳐 있는 구간을 찾을 것임.
    for(int station : stations){
        s = station - w, e = station + w;
        s = max(s, 1); e = min(e, n);
        int prev_e = overlaps.back().second;
        
        if(prev_e + 1 < s){ // 아예 새로운 구간이 시작되는 경우
            overlaps.push_back({s, e});
        }
        else{ // 이어지거나, 겹치는 경우
            overlaps.back().second = e;
        }
    }
    overlaps.push_back({n+1, n+1});
    
    
    // overlapping 결과 테스트
    // for(pii p : overlaps){
    //     cout<<p.first<<", "<<p.second<<endl;
    // }
    
    // sum of ceil(겹쳐 있지 않은 구간 / w)가 답.
    int answer = 0;
    s = 1;
    w = 2 * w + 1;
    for(pii overlap : overlaps){
        e = overlap.first - 1;
        
        answer += (e - s + 1) / w;
        answer += ((e - s + 1) % w != 0);
        
        s = overlap.second + 1;
    }
    
    return answer;
}

/*
비어있는 공간만 찾으면 됨. 구현 문제 같음.
stations들이 겹쳐 있는 구간을 찾는 문제로 바꾸면 쉬울 것 같은데?

*/
#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii; // [start, end]

int solution(int n, vector<int> stations, int w)
{
    // 첫 번째 전, 마지막 이후는 예외처리
    vector<pii> empties;
    if(stations.front() - w > 1) empties.push_back({1, stations[0] - w - 1}); // 첫번째 전
    
    for(int i = 0; i<stations.size() - 1; i++){
        int start = stations[i] + w + 1; 
        int end = stations[i+1] - w - 1;
        if(start <= end){ // 굳이 while문 쓸 필요 없이, 겹친다면 다음 것 보면 된다.
            empties.push_back({start, end});
            continue;
        }
    }
    
    if(stations.back() + w < n) empties.push_back({stations.back() + w + 1, n}); // 마지막 후
    
    // for(pii p : empties) cout<<p.first<<", "<<p.second<<endl;
    
    w = 2*w + 1;
    int answer = 0;
    for(pii p : empties){
        int len = p.second - p.first + 1;
        answer += (len + w - 1) / w;
    }

    return answer;
}

/*
n이 2억이므로 n을 순회하면 안 된다. station 값을 이용해 설치 안 된 모든 구간을 알아내야 한다.
*/
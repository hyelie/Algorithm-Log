// 기지국 설치

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int solution(int n, vector<int> stations, int w)
{
    vpii c;
    // c : 전파가 있는 아파트들(connected). v.first : 시작점, v.second : 끝나는 점
    // u : 전파가 없는 아파트들(unconnected)
    c.push_back({0, 0});
    c.push_back({stations[0] - w, stations[0] + w});
    for(int i = 1; i<stations.size(); i++){
        if(stations[i] - w <= c[c.size()-1].second + 1){
            c[c.size()-1].second = stations[i] + w;
        }
        else{
            c.push_back({stations[i] - w, stations[i] + w});
        }
    }
    c[0].first = c[0].first < 1 ? 1 : c[0].first;
    c[c.size()-1].second = c[c.size()-1].second > n ? n : c[c.size()-1].second;
    c.push_back({n+1, n+1});
    
    int answer = 0;
    w = w + w + 1;
    
    for(int i = 0; i<c.size()-1; i++){
        if(c[i].second < c[i+1].first){
            answer += ceil(((double)c[i+1].first - (double)c[i].second - 1) / w);
        }
    }

    

    return answer;
}
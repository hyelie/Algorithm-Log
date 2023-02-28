#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pii;

// 끝 시간 오름차순, 같으면 시작 시간 오름차순
bool cmp(pii &a, pii &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int solution(vector<vector<string>> book_time) {
    vector<pii> times; // .first : 시작 시간, .second : 끝나는 시간
    for(vector<string> v : book_time){
        int start = stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3, 2));
        int end = stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3, 2)) + 10;
        times.push_back({start, end});
    }
    sort(times.begin(), times.end(), cmp);
    
    int answer = -1;
    
    vector<int> startTimes;
    for(pii t : times){
        startTimes.push_back(t.first);
    }
    sort(startTimes.begin(), startTimes.end(), less<int>()); // 오름차순
    
    int n = times.size();
    for(int i = 0; i<n; i++){
        int endTime = times[i].second, cnt = 1;
        for(int j = i+1; j<n; j++){
            if(times[j].first < endTime) cnt++;
        }
        answer = max(answer, cnt);
    }
    
    return answer;
}

/*
끝시간 오름차순 정렬, 다음 index의 시작시간이 그것보다 작거나 같은들의 max값
이 부분 : 겹치는 후보군
*/
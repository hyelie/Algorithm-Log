#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool cmp(pii &a, pii &b){ // 끝나는 시간 오름차 정렬
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int string_to_milisecond(string &time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    int ms = stoi(time.substr(9, 3));
    
    return ms + 1000 * s + 1000 * 60 * m + 1000 * 60 * 60 * h;
}

int parse_duration(string &duration){
    double d = stod(duration.substr(0, duration.length()-1));
    return d * 1000;
}


int solution(vector<string> lines) {
    vector<pii> v;
    for(string &line : lines){
        string date, time, duration;
        istringstream iss(line);
        iss >> date >> time >> duration;
        
        int end_time = string_to_milisecond(time);
        v.push_back({end_time - parse_duration(duration) + 1, end_time});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int answer = 0;
    for(int i = 0; i<v.size(); i++){
        int cnt = 1;
        for(int j = i+1; j<v.size(); j++){
            if(v[j].first < v[i].second + 1000) cnt++;
        }
        answer = max(answer, cnt);
    }
    return answer;
}
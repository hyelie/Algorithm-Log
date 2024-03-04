#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <iterator>

using namespace std;

string MinuteToString(int m){
    int h = m / 60;
    string hs = to_string(h);
    if(h < 10) hs = "0" + hs;
    
    m = m - 60 * h;
    string ms = to_string(m);
    if(m < 10) ms = "0" + ms;
    return hs + ":" + ms;
}

int StringToMinute(string s){
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 5));
    return 60 * h + m;
}

typedef pair<int, int> pii; // [시간, 본인여부(1, 아니면 0)]
typedef multiset<pii>::iterator miter;

struct cmp{ // 시간 빠른거 - 타인부터
    bool operator() (const pii &a, const pii &b) const{
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

// cur_time보다 작은 것들을 모두 queue에 넣음
void Insert(queue<bool> &q, multiset<pii> &waits, int cur_time, miter &iter){
    while(1){
        if(iter == waits.end()) return;
        
        pii cur = *iter;
        if(cur.first > cur_time) return;
        
        q.push(cur.second == 1);
        iter++;
    }
}

bool Pop(queue<bool> &q, int m){
    while(!q.empty() && m--){
        bool front = q.front();
        if(front) return true;
        
        q.pop();
    }
    return false;
}

// arrive_time에 도착했을 때 못타면 true, 아니면 false
// O(n)
bool CanNotGo(int arrive_time, int n, int t, int m, multiset<pii> &waits){
    waits.insert({arrive_time, 1});
    queue<bool> q; // 줄. 본인이면 true, 아니면 false
    int i;
    
    miter iter = waits.begin();
    
    int cur_time = StringToMinute("09:00"); // 09시부터 n회 t분 간격, m명이 탈 수 있음.
    Insert(q, waits, cur_time, iter); // 9시까지 온애 전부 줄세움
    
    // 9시부터 n대 옴.
    bool canGo = false;
    while(n--){
        canGo = Pop(q, m);
        if(canGo) break;
        
        cur_time += t;
        Insert(q, waits, cur_time, iter);
    }
    
    waits.erase({arrive_time, 1});
    return !canGo;
}

string solution(int n, int t, int m, vector<string> timetable) {
    // init
    multiset<pii> waits;
    for(int i = 0; i<timetable.size(); i++){
        waits.insert({StringToMinute(timetable[i]), 0});
    }
    
    // lb
    int start = 0, end = StringToMinute("24:00"), mid;
    int limit = end;
    while(start < end){
        mid = (start + end) / 2;
        if(CanNotGo(mid, n, t, m, waits)) end = mid; // 탈 수 없으면 시간을 더 당김
        else start = mid + 1;
    } // 결과 : 탈 수 없는 최소값
    
    // int temp = StringToMinute("09:00");
    // cout<<CanNotGo(temp, n, t, m, waits)<<endl;
    
    if(end == 0){ // 어떻게 해도 못 탐
        return "00:00";
    }
    if(end == limit){ // 어떻게 해도 탐.
        return "23:59";
    }
    else{ // 보통 경우
        return MinuteToString(end-1);
    }
}
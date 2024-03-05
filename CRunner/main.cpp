#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <cmath>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <iterator>

using namespace std;

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

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

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> waits(timetable.size());
    for(int i = 0; i<timetable.size(); i++){
        waits[i] = StringToMinute(timetable[i]);
    }
    sort(waits.begin(), waits.end(), less<int>());
    
    int start_time = StringToMinute("09:00");
    queue<int> q; // 대기열
    
    // 1. 9시 이전에 온 사람 다 넣음
    int i;
    for(i = 0; i<waits.size(); i++){
        if(waits[i] <= start_time) q.push(waits[i]);
		else break;
    }
    
    int latest = -1;
    int latest_q_size = 0;
    while(n--){
        // 2. 대기열에 있는 사람 t명 pop
        int tempm = m;
        latest_q_size = q.size();
        while(!q.empty() && tempm--){
            latest = q.front();
            q.pop();
        }
        
        if(n == 0) break;
        
        // 3. 다음 차시간 전에 줄 선 사람 모두 push
        start_time += t;
        for(; i<waits.size(); i++){
            if(waits[i] <= start_time) q.push(waits[i]);
        }
    }
    
    // 다 못 탄 경우
    if(i < waits.size()){
        return MinuteToString(latest-1);
    }
    // 다 탄 경우
    if(i == waits.size()){
        // 막차가 가득 찬 경우
        if(latest_q_size == m) return MinuteToString(latest-1);
        // 막차가 가득 안 찬 경우
        return MinuteToString(start_time);
    }
}

/*
모든 크루가 타고
- 탈 수 있는 여유가 있는 경우 -> 마지막 버스 시간
- 탈 수 있는 여유가 없는 경우 -> 제일 마지막에 타는 크루보다 1분 빨리.
*/

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int n = 1, t = 1, m = 1;
	vector<string> timetable = {"23:59"};

	solution(n, t, m, timetable);
	
	return 0;
}
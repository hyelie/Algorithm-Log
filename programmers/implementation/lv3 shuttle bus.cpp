// 셔틀버스

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int stringToMinute(string s){
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
}

string timeToString(int t){
    int hour = t/60;
    string shour;
    if(hour == 0){
        shour = "00";
    }
    else if(hour < 10){
        shour = "0" + to_string(hour);
    } else{
        shour = to_string(hour);
    }
    
    int minute = t%60;
    string sminute;
    if(minute == 0)
        sminute = "00";
    else if(minute < 10){
        sminute = "0" + to_string(minute);
    } else{
        sminute = to_string(minute);
    }
    
    return shour + ":" + sminute;
    
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> crews;
    int firstBusArriveTime = stringToMinute("09:00");
    int lastBusArriveTime = firstBusArriveTime + (n-1) * t;
    for(string s : timetable){
        int crewArriveTime = stringToMinute(s);
        if(crewArriveTime > lastBusArriveTime) continue;
        crews.push_back(crewArriveTime);
    }
    sort(crews.begin(), crews.end());
    
    for(int objectTime = lastBusArriveTime + 1; objectTime >= 0; objectTime--){
        bool flag = false;
        vector<int> bus(n, m);
        if(objectTime == 541){
            cout<<"CHECK"<<endl;
        }
        for(int ci = 0, bi = 0; ci < crews.size() && bi < n; ci++){
            int busArriveTime = firstBusArriveTime + t * bi;
            if(crews[ci] <= busArriveTime){
                if(crews[ci] > objectTime && objectTime <= busArriveTime){
                    flag = true;
                    break;
                } else{
                    bus[bi]--;
                }
            } else{
                ci--; bi++;
                if(bi >= n) break;
            }
            if(bus[bi] == 0){
                bi++;
            }
        }
        for(int bi = 0; bi < n; bi++){
            int busArriveTime = firstBusArriveTime + t * bi;
            if(objectTime <= busArriveTime && bus[bi] > 0){
                flag = true;
                break;
            }
        }
        if(flag) return timeToString(objectTime);
    }
    
    return timeToString(0);
}
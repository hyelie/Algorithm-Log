// 주차 요금 계산

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

bool cmp(pii &a, pii &b){
    return a.first < b.first;
}

// .first : hour, .second : minute
pii strToTimePii(string time){
    return {stoi(time.substr(0, 2)), stoi(time.substr(3, 2))};
}

int calCost(int minutes, vector<int>& fees){
    if(minutes < fees[0]) return fees[1];
    else{
        return fees[1] + ceil((double)(minutes - fees[0]) / fees[2]) * fees[3];
    }
}

int calMinutes(string start_time, string end_time){
    pii start = strToTimePii(start_time), end = strToTimePii(end_time);
    return (end.first - start.first) * 60 + end.second - start.second; 
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    unordered_map<string, string> parking_lot; // um["0000"] == true : 입차된 시간
    unordered_map<string, int> um; // um["0000"] - 차번 0000의 시간
    string time, number, type;
    istringstream iss;
    for(string s : records){
        iss.clear(); iss.str(s);
        iss >> time >> number >> type;
        
        if(type == "IN"){
            parking_lot[number] = time;
        } else{ // type == "OUT"
            int t = calMinutes(parking_lot[number], time);
            parking_lot.erase(number);
            um[number] += t;
        }
    }
    
    string deadline = "23:59";
    for(auto [number, start_time] : parking_lot){
        um[number] += calMinutes(start_time, deadline);
    }
    
    vector<pii> result;    
    for(auto [car_number, total_time] : um){
        result.push_back({stoi(car_number), total_time});
    }
    sort(result.begin(), result.end(), cmp);
    vector<int> answer;
    for(pii temp : result){
        answer.push_back(calCost(temp.second, fees));
    }
    
    
    
    return answer;
}
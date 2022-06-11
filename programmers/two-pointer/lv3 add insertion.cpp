// 광고 삽입

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

string secondToString(int s){
    int h = s / 3600; s %= 3600;
    int m = s / 60; s %= 60;
    
    string sh = to_string(h);
    if(h<10){
        sh = "0" + sh;
    }
    string sm = to_string(m);
    if(m < 10){
        sm = "0" + sm;
    }
    string ss = to_string(s);
    if(s < 10){
        ss = "0" + ss;
    }
    return sh + ":" + sm + ":" + ss;
}

int stringToSecond(string s){
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    return 3600 * h + 60 * m + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int num_logs = logs.size();
    int splay_time = stringToSecond(play_time), sadv_time = stringToSecond(adv_time);
    vector<int> viewers(splay_time+1, 0);
    for(string s : logs){
        viewers[stringToSecond(s.substr(0, 8))]++;
        viewers[stringToSecond(s.substr(9, 8))]--;
    }
    
    // viewers[i] : i시간에 보는 사람들 수
    for(int i = 1; i<splay_time+1; i++){
        viewers[i] += viewers[i-1];
    }
    
    long long max_adv_time = 0, window_sum = 0;
    string answer = "";
    for(int i = 0; i<sadv_time; i++){
        window_sum += viewers[i];
        answer = secondToString(0);
    }
    max_adv_time = window_sum;
    
    
    for(int i = sadv_time; i<splay_time+1; i++){
        window_sum += (viewers[i] - viewers[i-sadv_time]);
        if(max_adv_time < window_sum){
            answer = secondToString(i - sadv_time + 1);
            max_adv_time = window_sum;
        }
    }
    
    return answer;
}
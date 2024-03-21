#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll string_to_second(string str){
    ll h = stol(str.substr(0, 2));
    ll m = stol(str.substr(3, 2));
    ll s = stol(str.substr(6, 2));
    return s + 60 * m + 60 * 60 * h;
}

string second_to_string(ll i){
    string h = to_string(i / (60 * 60));
    if(h.length() == 1) h = "0" + h; 
    
    i -= stol(h) * (60 * 60);
    string m = to_string(i / 60);
    if(m.length() == 1) m = "0" + m;
    
    string s = to_string(i % 60);
    if(s.length() == 1) s = "0" + s;
    
    return h + ":" + m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    // init
    ll play_time_second = string_to_second(play_time);
    ll adv_time_second = string_to_second(adv_time);
    
    // psum
    vector<int> psum(play_time_second + 1, 0);
    for(string log : logs){
        string start_time = log.substr(0, 8), end_time = log.substr(9, 8);
        ll start_second = string_to_second(start_time), end_second = string_to_second(end_time);
        psum[start_second]++;
        psum[end_second]--;
    }
    
    // psum 계산: psum[i] : i시간에 몇명 봤는지 적혀있음.
    for(int i = 1; i<play_time_second + 1; i++){
        psum[i] += psum[i-1];
    }
    
    // window init
    ll window_sum = 0;
    for(int i = 0; i<adv_time_second; i++){
        window_sum += psum[i];
    }
    
    // move window
    ll max_sum = window_sum;
    string answer = second_to_string(0);
    // for(int i = adv_time_second; i<play_time_second + 1; i++){
    //     window_sum += psum[i] - psum[i - adv_time_second];
    //     if(max_sum < window_sum){
    //         window_sum = max_sum;
    //         answer = second_to_string(i - adv_time_second + 1);
    //     }
    // }
    for(int i = 0; i<play_time_second - adv_time_second + 1; i++){
        window_sum += psum[i + adv_time_second] - psum[i];
        if(max_sum < window_sum){
            window_sum = max_sum;
            answer = second_to_string(i + 1);
        }
    }

    return answer;
}
// 방금그곡

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

// .first : 재생된 시간, .second : 입력된 index
bool comp(pii &a, pii &b){
    if(a.first == b.first){
        return a.second < b.second;
    } else{
        return a.first > b.first;
    }
}

int getTimeDiff(string &a, string &b){
    string ah = a.substr(0, 2), am = a.substr(3, 2); 
    string bh = b.substr(0, 2), bm = b.substr(3, 2);
    return (stoi(bh) - stoi(ah)) * 60 + (stoi(bm) - stoi(am));
}

string pitchToNum(string s){
    vector<string> pitches = {"#C", "#D", "#F", "#G", "#A"};
    int size = s.size();
    for(int i = 0; i<size; i++){
        if(s[i] == '#'){
            swap(s[i], s[i-1]);
        }
    }
    string result = "";
    for(int i = 0; i<size; i++){
        if(s[i] == '#'){
            result += to_string(find(pitches.begin(), pitches.end(), s.substr(i, 2)) - pitches.begin());
            i++;
        } else{
            result += s[i];
        }
    }
    return result;
}

bool isMInInfos(string m, string infos){
    int m_size = m.length(), infos_size = infos.length();
    if(infos_size < m_size) return false;
    bool result;
    for(int i = 0; i<=infos_size - m_size; i++){
        result = true;
        for(int j = 0; j<m_size; j++){
            if(m[j] != infos[i + j]){
                result = false;
            }
        }
        if(result == true) return true;
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    int size = musicinfos.size();
    vector<vector<string>> musicv(size, vector<string>(3));
    // [i][0] = 시간, [i][1] = 곡이름, [i][2] = 악보 정보
    istringstream ss;
    for(int i = 0; i<size; i++){
        ss.str(musicinfos[i]);
        string buffer;
        vector<string> infos;
        while(getline(ss, buffer, ',')){
            infos.push_back(buffer);
        }
        
        int playtime = getTimeDiff(infos[0], infos[1]);
        musicv[i][0] = to_string(playtime);
        musicv[i][1] = infos[2];
        
        string music_pitch = pitchToNum(infos[3]);
        int q = playtime / music_pitch.length(), r = playtime % music_pitch.length();
        string played_pitch = "";
        while (q-- > 0){
            played_pitch += music_pitch;
        } played_pitch += music_pitch.substr(0, r);
        musicv[i][2] = played_pitch;

        ss.clear();
    }
    
    
    vector<pii> candidates;
    for(int i = 0;i <size; i++){
        int isCorrespond = false;
        m = pitchToNum(m);
        if(isMInInfos(m, musicv[i][2])) candidates.push_back({stoi(musicv[i][0]), i});     
    }
    
    if(candidates.size() == 0) return "(None)";
    sort(candidates.begin(), candidates.end(), comp);
    return musicv[candidates[0].second][1];
}
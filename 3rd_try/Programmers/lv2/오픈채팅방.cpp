#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

typedef pair<string, string> pss;

map<string, string> m; // [uid, nickname]

string get_log(string uid, string command){
    if(command == "Enter"){
        return m[uid] + "님이 들어왔습니다.";
    }
    else{ // command == "Leave"
        return m[uid] + "님이 나갔습니다.";
    }
}

vector<string> solution(vector<string> records) {
    // init
    vector<pss> infos;
    for(string record : records){
        istringstream iss(record);
        string command, uid, nickname;
        iss >> command;
        
        if(command == "Enter"){
            iss >> uid >> nickname;
            m[uid] = nickname;  
            infos.push_back({uid, command});
        }
        else if(command == "Leave"){
            iss >> uid;
            infos.push_back({uid, command});
        }
        else{ // command == "Change"
            iss >> uid >> nickname;
            m[uid] = nickname;
        }
    }
    
    vector<string> answer;
    for(pss info: infos){
        answer.push_back(get_log(info.first, info.second));
    }
    return answer;
}

// 풀이 8분, 디버깅 2분
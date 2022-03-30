// 오픈채팅방

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {    
    stringstream ss;
    string action, uid, nickname;
    
    map<string, string> m;  // uid - nickname map
           
    // 모든 record를 순회하면서 uid에 해당하는 nickname을 제일 최신의 것으로 변경할 것임.
    for(string elem : record){
        ss.clear();
        ss.str(elem);
        //ss >> action >> uid >> nickname;
        ss >> action >> uid;
        if(action == "Enter" || action == "Change"){
            ss >> nickname; 
            m[uid] = nickname;
        }
    }
    
    vector<string> answer;
    for(string elem : record){
        ss.clear();
        ss.str(elem);
        ss >> action >> uid;
        if(action == "Enter"){
            answer.push_back(m[uid] + "님이 들어왔습니다.");
        } else if(action == "Leave"){
            answer.push_back(m[uid] + "님이 나갔습니다.");
        } else continue;
    }
    return answer;
}

// 일단 






/*

// 입장 : Enter [UID] [Nickname]
// 퇴장 : Leave [UID] [Nickname]
// 변경 : Change [UID] [Nickname]
// UID, Nickname 길이는 1~10. 대소문자를 구별함.

// 닉네임 변경 : enter되어 있는 UID가 change함
// 또는 leave 후 enter 시 다른 nickname으로 들어옴.

// 입력되는 순서대로 map 써서 uid에 해당하는 name을 저장하게 함.
// enter할 때 이미 있는 값이라면 업데이트하고, 아니라면 새 노드 추가
// change하면 찾아서 업데이트

// 삽입하는 데 nlogn
// 처음부터 끝까지 다 보는 데 nlogn

string Enter(string name){
    return name.append("님이 들어왔습니다.");
}

string Leave(string name){
    return name.append("님이 나갔습니다.");
}

vector<string> parse(string input){
    vector<string> substr;
    int strlen = input.length();
    for(int i = 0, j = 0; i<=strlen; i++){
        if(input[i] == ' ' || i == strlen){
            substr.push_back(input.substr(j, i-j));
            i++;
            j = i;
        }
    }
    
    return substr;
}

vector<string> solution(vector<string> record) {    
    map<string, string> nl;
    queue<pair<int, string>> q;
        
    stringstream ss; string action, uid, nickname;
    
    
    int record_size = record.size();
    for(int i = 0; i<record_size; i++){
        ss.str(record[i]);
        ss>>action;
        if(action == "Enter"){
            ss>>uid>>nickname;
            q.push({1, uid});
            nl[uid] = nickname;
        }
        else if(action == "Leave"){
            ss>>uid;
            q.push({2, uid});
        }
        else if(action == "Change"){
            ss>>uid>>nickname;
            nl[uid] = nickname;
        }
        ss.clear();
        // queue에는 명령어랑 uid만 넣음, map에는 key-value 쌍 넣어줌
        //nl.insert({each_line[1], each_line[2]});
        
    }
    
    vector<string> answer;
    
    while(!q.empty()){
        string each_output;
        // enter
        if(q.front().first == 1){
            each_output = Enter(nl[q.front().second]);
        }
        else{
            each_output = Leave(nl[q.front().second]);
        }
        answer.push_back(each_output);
        q.pop();
    }
    
    
    return answer;
}
*/

// 길이 100,000
// 제곱 : 10000000000 십억 -> 1초 -> linear 아니면 nlogn으로 풀어야함
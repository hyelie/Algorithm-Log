#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

int n;
vector<int> ips; // 0 : 할당되지 않은 상태, 1 : 사용하지 않는 상태, 2 : 사용중인 상태
map<string, int> m; // m[string] : 최근에 사용했던 ip.
                    // find로 할당받았는지 검사 가능
                    
vector<string> answer;

void addAnswer(string computer, string ip){
    if(ip == "reject"){
        answer.push_back(computer + " reject");
    }
    else{
        answer.push_back(computer + " 192.168.0." + ip);
    }
}

int getNotAllocateMinIP(){ // 할당되지 않은 ip 중 최솟값
    for(int i = 1; i<=n; i++){
        if(ips[i] == 0) return i;
    }
    return -1; // 전부 할당되었음
}

int getNotUsingMinIP(){ // 사용중이지 않은 IP 중 제일 작은 것
    for(int i = 1; i<=n; i++){
        if(ips[i] == 1) return i;
    }
    return -1; // 전부 사용중
}

vector<string> solution(int nn, vector<string> queries) {
    n = nn;
    ips.resize(n+1);
    fill(ips.begin(), ips.end(), 0);
    string computer, type;
    for(string query : queries){
        istringstream iss;
        iss.str(query);
        iss >> computer >> type;
        iss.clear();

        if(type == "request"){ // 요청
            if(m.find(computer) == m.end()){ // 할당받은 적 없음
                int notAllocatedMinIP = getNotAllocateMinIP();
                if(notAllocatedMinIP != -1){
                    m[computer] = notAllocatedMinIP;
                    ips[notAllocatedMinIP] = 2;
                    addAnswer(computer, to_string(notAllocatedMinIP));
                    continue;
                }
                else{
                    int notUsingMinIP = getNotUsingMinIP();
                    if(notUsingMinIP != -1){
                        m[computer] = notUsingMinIP;
                        ips[notUsingMinIP] = 2;
                        addAnswer(computer, to_string(notUsingMinIP));
                        continue;
                    }
                    else{
                        addAnswer(computer, "reject");
                        continue;
                    }
                }
            }
            else{ // 할당받았음
                if(ips[m[computer]] == 2){ // 다른 컴에서 사용중인 상태
                    int notAllocatedMinIP = getNotAllocateMinIP();
                    if(notAllocatedMinIP != -1){
                        m[computer] = notAllocatedMinIP;
                        ips[notAllocatedMinIP] = 2;
                        addAnswer(computer, to_string(notAllocatedMinIP));
                        continue;
                    }
                    else{
                        int notUsingMinIP = getNotUsingMinIP();
                        if(notUsingMinIP != -1){
                            m[computer] = notUsingMinIP;
                            ips[notUsingMinIP] = 2;
                            addAnswer(computer, to_string(notUsingMinIP));
                            continue;
                        }
                        else{
                            addAnswer(computer, "reject");
                            continue;
                        }
                    }
                }
                else{ // 다른 컴에서 안쓰는 상태
                    ips[m[computer]] = 2;
                    addAnswer(computer, to_string(m[computer]));
                }
            }
        }
        else if(type == "release"){ // 반납
            ips[m[computer]] = 1;
        }
    }

    return answer;
}

/*
요청 : 새 ip 발급
 - 할당받지 않은 게 할당 요청
    - 할당되지 않은 ip중 제일 작은 것
    - 모든게 할당되었다면, 사용하지 않는 것 중 제일 작은 ip
    - 모든게 사용중이라면 거부
 - 할당받았던 컴퓨터가 ip요청
    - 최근에 썼던 ip 할당
    - 그게 사용중이면 한번도 할당되지 않았던 ip 중 제일 작은 ip
    - 모든 ip가 1번이상할당되어싿면 사용하지 않는 것 중 제일 작은 ip
    - 모든게 사용중이라면 거부
반납 : 반납, 반납 전까지 할당 불가
*/
// 신고 결과 받기

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    map<string, int> reported_num_map; // string에 해당하는 사람이 신고당한 횟수
    map<string, vector<string>> report_map; // string에 해당하는 사람이 신고한 사람들 vector
    for(string s : id_list){
        reported_num_map[s] = 0;
    }
    
    for(string s : report){
        int length = s.length();
        for(int i = 0; i<length; i++){
            if(s[i] == ' '){
                string reporter = s.substr(0, i);
                string reported = s.substr(i+1, length - i - 1);
                reported_num_map[reported]++;
                report_map[reporter].push_back(reported);
            }
        }
    }
    
    vector<int> answer;
    int cnt;
    for(string id : id_list){
        cnt = 0;
        for(string s : report_map[id]){
           if(reported_num_map[s] >= k) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}

/*

map<string, int>로 string-int로 id idx를 줄 수 있겠고

1) set<pss>로 중복된 report를 처리해도 될 것 같고
2) report를 sort 후 unique 써서 동일한 유저 신고 수를 없앤 다음에 모든 것을 처리해도 될 것 같은데
2)가 더 간단해 보이니 그리 하자.

*/
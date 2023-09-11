#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

// 4^15는 1억이 넘으므로 전부 다 계산하고 뽑는 것은 안 된다. 적당히 찾아야 한다.

/*
    p / 4 -> 윗 세대의 index가 나옴.
    예를 들어 9 / 4 = 2.x -> 윗 세대는 
    1 2 3 4 / 4 -> 0 번째
    5 6 7 8 / 4 -> 1 번째
    9 10 11 12 / 4 -> 2 번째
    -> (p-1) / 4 내림하면 되겠네.
    vector에 넣으면 뒤에서부터 보면 될 듯.
*/

// record[i] : i+1번째 generation에서 어떤 index를 가지는지
// ex) record[2] == 2 : 3번째 generation에서 index가 2
// 2번째 generation까지 계산함. 1번째 generation은 있기 때문.
vector<int> getRecords(int n, int p){
    vector<int> records; 
    records.push_back((p-1) % 4);
    while(n > 2){
        int before = ceil(((double)p)/4);
        records.push_back((before-1) % 4);
        
        p = before;
        n--;
    }
    reverse(records.begin(), records.end());
    return records;
}

// n : 세대, p : 개체
// 윗세대가 어떤 것인지 찾아야 한다.
string process(int n, int p){
    if(n == 1) return "Rr";
    
    map<string, vector<string>> m;
    m["RR"] = {"RR", "RR", "RR", "RR"};
    m["Rr"] = {"RR", "Rr", "Rr", "rr"};
    m["rr"] = {"rr", "rr", "rr", "rr"};
    
    vector<int> records = getRecords(n, p);
    
    string cur = "Rr";
    for(int record : records){
        //cout<<"cur : "<<cur<<", record : "<<record<<endl;
        cur = m[cur][record];
        
    }
    //cout<<endl;
    
    return cur;
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for(vector<int> query : queries){
        answer.push_back(process(query[0], query[1]));
    }
    return answer;
}
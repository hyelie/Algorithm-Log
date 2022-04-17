// 후보키

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

bool isUnique(string keys, vector<vector<string>>& relation){
    sort(keys.begin(), keys.end());
    set<string> s;
    int num_rows = relation.size(), num_keys = keys.length();
    for(int i = 0; i<num_rows; i++){
        string temp_key = "";
        for(int k = 0; k<num_keys; k++){
            temp_key += relation[i][stoi(keys.substr(k, 1))];
        }
        s.insert(temp_key);
    }
    if(s.size() != num_rows) return false;
    else return true;
}

void combination(int curD, int maxD, int prevIdx, int maxIdx, string key, vector<bool> &isUsed, vector<string> &keyList){
    if(curD == maxD){
        keyList.push_back(key);
        return;
    }
    for(int i = prevIdx + 1; i<maxIdx; i++){
        isUsed[i] = true;
        combination(curD + 1, maxD, i, maxIdx, key + to_string(i), isUsed, keyList);
        isUsed[i] = false;
    }
}

int solution(vector<vector<string>> relation) {    
    int num_keys = relation[0].size();
    vector<bool> isUsed(num_keys, false);
    vector<string> keyList;
    for(int i = num_keys-1; i>=0; i--){
        combination(0, i + 1, -1, num_keys, "", isUsed, keyList);    
    }
    // keyList : 가능한 key의 조합
    
    map<string, int> m;
    for(int i = 0; i<keyList.size(); i++){
        m[keyList[i]] = isUnique(keyList[i], relation);
        //cout<<keyList[i]<<" "<<m[keyList[i]]<<endl;
    }
    
    queue<string> q;
    string maxKey = "";
    for(int i = 0; i<num_keys; i++){
        maxKey += to_string(i);
    } q.push(maxKey);
    
    set<string> s;
    while(!q.empty()){
        string frontKey = q.front(); q.pop();
        bool isMinimal = true;
        for(int i = 0; i<frontKey.length(); i++){
            string downKey = frontKey.substr(0, i) + frontKey.substr(i + 1, frontKey.length() - i - 1);
            if(m[downKey]){
                isMinimal = false;
                q.push(downKey);
            }
        }
        if(frontKey.size() == 1 || isMinimal) s.insert(frontKey);
    }
    
    return s.size();
}

// 1. 키들의 조합을 고르는 방법 -> 조합. cC1, cC2, ... , cCc로 뽑을 수 있는 모든 경우의 수이다.
// 2. 1.에서 고른 키들로 유일성을 만족하는지 검사(해당 키에 해당하는 relation 개수가 전체 다인지) OK
// 3. 1.과 2.를 만족하는 key 중 포함관계가 있는지.
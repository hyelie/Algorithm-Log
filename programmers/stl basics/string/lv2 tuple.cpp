// 튜플

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool comp(vector<int> &a, vector<int> &b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    s = s.substr(1, s.length()-2);
    vector<string> each_set;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '{'){
            int j = i;
            while(s[i] != '}') i++;
            each_set.push_back(s.substr(j+1, i-j-1));
        }
    }
    
    vector<vector<int>> v(each_set.size());
    for(int i = 0; i<v.size(); i++){
        istringstream ss(each_set[i]);
        string buffer;
        while(getline(ss, buffer, ',')){
            v[i].push_back(stoi(buffer));
        }
    }
    
    sort(v.begin(), v.end(), comp);
    vector<int> answer;
    unordered_set<int> us;
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            if(us.find(v[i][j]) == us.end()){
                answer.push_back(v[i][j]);
                us.insert(v[i][j]);
            }
        }
    }
    
    return answer;
}
// 단어 변환

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool isOneCharDifferent(string &target, string &word){
    int cnt = 0;
    for(int i = 0; i<target.length(); i++){
        if(target[i] != word[i]) cnt++;
    }
    return cnt == 1;
}

// BFS
int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    vector<int> dist(words.size()+1, 0);
    words.push_back(begin);
    queue<string> q;
    
    int answer = 0;
    q.push(begin);
    while(!q.empty()){
        
        string s = q.front(); q.pop();
        int sidx = find(words.begin(), words.end(), s) - words.begin();
        
        for(int i = 0; i<words.size(); i++){
            if(dist[i] == 0 && isOneCharDifferent(s, words[i])){
                q.push(words[i]);
                dist[i] = dist[sidx] + 1;
            }
        }
    }
    
    return dist[find(words.begin(), words.end(), target) - words.begin()];
}
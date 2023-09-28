#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// 가장 짧은 변환 과정 - BFS

int len;
map<string, bool> visited; // visited[i] : string i를 사용했는지 여부
map<string, vector<string>> nextMap; // nextMap[i] : i에서 바꿀 수 있는 string vector

struct info{
    string s;
    int dist;  
};

// string a를 b로 바꿀 수 있는지 여부
bool canTransfer(string &a, string &b){
    int cnt = 0;
    for(int i = 0; i < len; i++){
        if(a[i] != b[i]) cnt++;
        if(cnt >= 2) break;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    // init
    len = begin.length();
    words.push_back(begin);
    for(string word : words){
        visited[word] = false;
    }
    int wsize = words.size();
    for(int i = 0; i<wsize; i++){
        for(int j = i+1; j<wsize; j++){
            if(canTransfer(words[i], words[j])){
                nextMap[words[i]].push_back(words[j]);
                nextMap[words[j]].push_back(words[i]);
            }
        }
    }
    
    // solve : BFS
    queue<info> q;
    info i; i.s = begin; i.dist = 0;
    q.push(i);
    visited[begin] = true;
    while(!q.empty()){
        string cur_s = q.front().s;
        int cur_d = q.front().dist;
        q.pop();
        if(cur_s == target) return cur_d;
        
        for(string next_s : nextMap[cur_s]){
            if(!visited[next_s]){
                info i; i.s = next_s; i.dist = cur_d + 1;
                q.push(i);
                visited[next_s] = true;
            }
        }
    }
    
    return 0;
}
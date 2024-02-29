#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n;

bool can_change(string &a, string &b){
    int len = a.length();
    int cnt = 0;
    for(int i = 0; i<len; i++){
        if(a[i] != b[i]) cnt++;
        if(cnt >= 2) return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    n = words.size();
    
    // early return
    bool target_in_words = false;
    for(string word : words){
        if(target == word){
            target_in_words = true;
            break;
        } 
    }
    if(!target_in_words) return 0;
    
    // set change info
    vector<vector<bool>> can_convert(n, vector<bool>(n, false));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j) continue;
            if(can_change(words[i], words[j])) can_convert[i][j] = true;
        }
    }
    vector<bool> visited(n, false);

    // bfs init
    queue<pii> q;
    for(int i = 0; i<n; i++){
        if(can_change(begin, words[i])){
            q.push({i, 1});
            visited[i] = true;
        }
    }
    
    // run bfs
    while(!q.empty()){
        int index = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if(words[index] == target) return depth;
        
        for(int i = 0; i<n; i++){
            if(i == index) continue;
            if(!visited[i] && can_convert[index][i]){
                visited[i] = true;
                q.push({i, depth + 1});
            }
        }
    }
    
    return 0;
}
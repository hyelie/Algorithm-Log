#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int len;

struct Info{
    int play, index;
};

struct cmp{
    // 조건 1. play가 큰 것.
    // 조건 2. index가 작은 것.
    bool operator()(Info &a, Info &b){
        if(a.play == b.play) return a.index > b.index;
        return a.play < b.play;
    }
};

typedef pair<string, int> psi;

bool cmpMap(psi &a, psi &b){
    if(a.second == b.second) return a.first < a.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    len = plays.size();
    
    // 1. 장르별 재생회수
    map<string, int> genrePlay; // genrePlay[i] : genre i의 재생 회수
    // 2. 장르 내부에서 재생회수 
    map<string, priority_queue<Info, vector<Info>, cmp>> genrePlayMap; // genrePlayMap[i] : genre i의 plays pa
    for(int i = 0; i<len; i++){
        string genre = genres[i];
        int play = plays[i];
        
        genrePlay[genre] += play;
        
        Info info; info.index = i; info.play = play;
        genrePlayMap[genre].push(info);
    }
    
    // map value로 정렬
    vector<psi> genrePlays(genrePlay.begin(), genrePlay.end());
    sort(genrePlays.begin(), genrePlays.end(), cmpMap);
    
    vector<int> answer;
    for(psi data : genrePlays){
        string genre = data.first;
        
        priority_queue<Info, vector<Info>, cmp> &pq = genrePlayMap[genre];
        answer.push_back(pq.top().index); pq.pop();
        if(!pq.empty()) answer.push_back(pq.top().index);
    }
    
    return answer;
}

/*
1. 장르별 재생회수 내림차순 정의
2. 장르 내부에서 재생회수 내림차순 정의
*/
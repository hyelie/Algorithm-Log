#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef pair<string, int> psi;

map<string, int> num_plays; // 장르별 총 재생회수
bool num_plays_sort(psi &a, psi &b){
    return a.second > b.second;
}

struct plays_comp{
    bool operator() (const pii &a, const pii &b) const{ // .first : 재생 회수 .second : 고유 번호
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
map<string, set<pii, plays_comp>> genres_plays; // 장르별 재생 목록

vector<int> solution(vector<string> genres, vector<int> plays) {
    // 초기값 설정
    int len = genres.size();
    for(int i = 0; i<len; i++){
        string genre = genres[i];
        int play = plays[i];
        num_plays[genre] += play;
        
        genres_plays[genre].insert({play, i});
    }
    
    vector<psi> v(num_plays.begin(), num_plays.end());
    sort(v.begin(), v.end(), num_plays_sort);
    
    vector<int> answer;
    
    for(psi elem : v){
        string genre = elem.first;
        set<pii, plays_comp> genres_plays_set = genres_plays[genre];
        
        auto iter = genres_plays_set.begin();
        answer.push_back((*iter).second);
        if(genres_plays_set.size() >= 2){
            iter++;
            answer.push_back((*iter).second);
        }
    }
    
    return answer;
}
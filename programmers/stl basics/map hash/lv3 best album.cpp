// 베스트앨범

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef pair<string, int> psi;

bool cmpPsi(psi& a, psi&b){
    return a.second > b.second;
}

bool cmpPii(pii &a, pii &b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> num_plays_genres;
    unordered_map<string, vector<pii>> genres_plays; // pii.first : 재생횟수, .second : 고유번호
    
    int size = plays.size();
    for(int i = 0; i<size; i++){
        num_plays_genres[genres[i]] += plays[i];
        genres_plays[genres[i]].push_back({plays[i], i});
    }
    
    vector<psi> v(num_plays_genres.begin(), num_plays_genres.end());
    sort(v.begin(), v.end(), cmpPsi);
    for(auto &[key, value] : genres_plays){
        sort(value.begin(), value.end(), cmpPii);
    }
    
    vector<int> answer;
    for(psi temp : v){
        vector<pii> genre_v = genres_plays[temp.first]; // temp.first : genre
        answer.push_back(genre_v[0].second);
        if(genre_v.size() > 1) answer.push_back(genre_v[1].second);
    }
    
    return answer;
}
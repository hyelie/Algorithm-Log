#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Info{
    string title;
    vector<string> refs;
    int default_point, num_external_link;
    double matching_point = 0;
    int index;
};

Info parse(string &word, string &page){ // 
    Info info;
    
    // meta tag 이름 찾기
    string meta_tag = "<meta property=\"og:url\" content=\"";
    int title_start_pos = page.find(meta_tag, 0) + meta_tag.size();
    string meta_close_tag = "\"/>";
    int title_end_pos = page.find(meta_close_tag, title_start_pos);
    info.title = page.substr(title_start_pos, title_end_pos - title_start_pos);
        
    int a_start_pos = 0, a_end_pos;
    vector<string> refs;
    while(1){
        string a_tag = "<a href=\"";
        a_start_pos = page.find(a_tag, a_start_pos);
        if(a_start_pos == string::npos) break;
        a_start_pos += a_tag.size();
        
        string a_close_tag = "\">";
        a_end_pos = page.find(a_close_tag, a_start_pos);
        string ref = page.substr(a_start_pos, a_end_pos - a_start_pos);
        refs.push_back(ref);
    }
    info.refs = refs;
    info.num_external_link = refs.size();
    
    // default point
    for(char &c : word) c = tolower(c);
    for(char &c : page) c = tolower(c);
    int default_point = 0, search_pos;
    while(1){
        search_pos = page.find(word, search_pos);
        if(search_pos == string::npos) break;
        if(search_pos - 1 >= 0 && isalpha(page[search_pos-1])){
        }
        else if(search_pos + word.size() < page.size() && isalpha(page[search_pos + word.size()])) {
        }
        else{
            default_point++;    
        }
  
        search_pos += word.size();
    }
    info.default_point = default_point;
    
    return info;
}

bool cmp(Info &a, Info &b){
    if(a.matching_point == b.matching_point) return a.index < b.index;
    
    return a.matching_point > b.matching_point;
}

int solution(string word, vector<string> pages) {
    // parse
    map<string, Info> m; // [title, Info] mapper
    int index = 0;
    for(string page : pages){
        Info i = parse(word, page);
        i.index = index++;
        m[i.title] = i;
    }
    
    // link point 계산
    for(auto &[title, info] : m){
        for(string ref : info.refs){
            if(m.find(ref) == m.end()) continue;
            else m[ref].matching_point += (double)info.default_point / info.num_external_link;
        }
        info.matching_point += info.default_point;
    }
    
    vector<Info> answer;
    for(auto &[title, info] : m){
        answer.push_back(info);
    }
    sort(answer.begin(), answer.end(), cmp);
    
    return answer[0].index;
}

/*
기본 점수: 검색어가 등장하는 회수
default_point

외부 링크 수 : outgoing edge 개수
num_external_link

링크점수 : sum(ingoing vertex의 기본점수 / ingoing vertex의 outgoing edge 개수)
link_point

매칭 점수 : 기본 점수 + 링크 점수
matching_point
*/
// 매칭 점수

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct webdata{
    int index, basic_point, num_external_link;
    double link_point;
    string pagename;
    vector<string> hrefs;
};

bool cmp(webdata &a, webdata &b){
    if(a.link_point + a.basic_point == b.link_point + b.basic_point){
        return a.index < b.index;
    }
    else return a.link_point + a.basic_point > b.link_point + b.basic_point;
}

webdata summary(string word, string page){
    webdata wd; wd.index = wd.basic_point = wd.num_external_link = wd.link_point = 0;
    wd.pagename = "";
    
    // 해당 page 이름 뽑기
    string metatag = "<meta property=\"og:url\" content=\"";
    int pagename_start_idx = page.find(metatag) + metatag.length();
    int metatag_end_idx = page.find("\"/>", pagename_start_idx);
    wd.pagename = page.substr(pagename_start_idx, metatag_end_idx - pagename_start_idx);
    
    // 해당 page가 참조하는 외부 링크(및 그 수) 뽑기
    int hreftag_start_idx = 0, hreftag_end_idx = 0;
    string hreftag = "<a href=\"";
    while(1){
        hreftag_start_idx = page.find(hreftag, hreftag_end_idx);
        if(hreftag_start_idx == string::npos) break;
        hreftag_start_idx += hreftag.length();
        hreftag_end_idx = page.find("\">", hreftag_start_idx);
        wd.num_external_link++;
        wd.hrefs.push_back(page.substr(hreftag_start_idx, hreftag_end_idx - hreftag_start_idx)); // 참조하는 링크
    }
    
    // 해당 page의 기본 점수(word에 해당하는 문자열) 뽑기
    for(char& c : page) c = tolower(c);
    for(char& c : word) c = tolower(c);
    int word_start_idx = 0, wordsize = word.size(), pagesize = page.size();
    while(1){
        word_start_idx = page.find(word, word_start_idx);
        if(word_start_idx == string::npos) break;
        if(word_start_idx + wordsize >= pagesize
           || (word_start_idx - 1 >= 0 && !isalpha(page[word_start_idx - 1]) && word_start_idx + wordsize < pagesize && !isalpha(page[word_start_idx + wordsize]))){
            wd.basic_point++;
        }
        word_start_idx++;
    }
    /*cout<<"summary 결과"<<endl;
    cout<<"index : "<<wd.index<<endl;
    cout<<"basic_point : "<<wd.basic_point<<endl;
    cout<<"num_external_link : "<<wd.num_external_link<<endl;
    cout<<"link_point : "<<wd.link_point<<endl;
    cout<<"pagename : "<<wd.pagename<<endl;
    cout<<"참조하는 페이지 : "<<endl;
    for(string h : wd.hrefs){
        cout<<h<<endl;
    }
    cout<<endl;*/
    
    return wd;
}

int solution(string word, vector<string> pages) {
    map<string, int> mapper; // mapper[string] : string에 해당하는 pages index
    vector<vector<int>> adjacent(21, vector<int>(21, 0)); // adjacent[i][j] : i에서 j를 호출하는 갯수
    vector<webdata> v(pages.size());
    
    for(int i = 0; i<pages.size(); i++){
        webdata wd = summary(word, pages[i]);
        wd.index = i;
        mapper[wd.pagename] = i;
        v[i] = wd;
    }
    
    for(int i = 0; i<v.size(); i++){
        double link_point = (double)v[i].basic_point / (double)v[i].num_external_link;
        for(string& h : v[i].hrefs){
            if(mapper.find(h) != mapper.end())
                v[mapper[h]].link_point += link_point;
        }
        
        cout<<endl;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    return v[0].index;
}

/*

기본 점수 : text 중 검색어가 등장하는 횟수(대소문자 무시)
외부 링크 수 : 해당 페이지에서 다른 웹페이졸 연결된 링크 개수
링크 점수 : 해당 웹페이지로 링크걸린 다른 웹페이지의 기본점수 / 해당 웹페이지의 외부 링크 수의 총 합

*/
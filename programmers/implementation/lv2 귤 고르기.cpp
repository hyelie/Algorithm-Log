#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool cmp(const pii &a, const pii &b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {    
    // 크기별 귤 개수 정렬
    map<int, int> m;
    for(int t : tangerine){
        if(m.find(t) == m.end()) m[t] = 1;
        else m[t]++;
    }
    
    // 귤 개수 적은 것 부터 오름차순 정렬
    vector<pii> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    // 개수 작은 것부터 뺌
    int total = tangerine.size();
    for(int i = 0; i<v.size(); i++){
        if(total - v[i].second < k) return v.size() - i;
        total -= v[i].second;
    }
    
    int answer = 0;
    return answer;
}
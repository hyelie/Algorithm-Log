#include <string>
#include <vector>
#include <set>

using namespace std;

struct cmp{
    bool operator()(const int& a, const int& b) const{
        return a>b;
    }
};

vector<int> solution(int k, vector<int> score) {
    multiset<int, cmp> ms;
    multiset<int, cmp>::iterator iter;
    vector<int> answer;
    
    for(int point : score){
        ms.insert(point);
        
        if(ms.size() <= k){
            iter = ms.end();
            advance(iter, -1);
        }
        else{
            iter = ms.begin();
            advance(iter, k-1);
        }
        answer.push_back(*iter);
    }
    
    return answer;
}

// set같이 자동 정렬 되는 stl
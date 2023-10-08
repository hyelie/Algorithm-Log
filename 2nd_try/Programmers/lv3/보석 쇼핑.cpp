#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

set<string> cur_gems;
int num;
map<string, int> cur_gem_count;

bool isContainAll(){
    return cur_gems.size() == num;
}

void insert(string gem){
    cur_gem_count[gem]++;
    cur_gems.insert(gem);
}

void erase(string gem){
    cur_gem_count[gem]--;
    if(cur_gem_count[gem] == 0) cur_gems.erase(gem);
}

vector<int> solution(vector<string> gems) {
    set<string> s;
    for(string gem : gems){
        s.insert(gem);
        cur_gem_count[gem] = 0;
    }
    num = s.size();
    
    int start = 0, end = 0;
    insert(gems[start]);
    vector<int> answer = {-1, 100001};
    while(start < gems.size() && end < gems.size()){
        if(start > end){
            end = start;
            continue;
        }
        
        if(isContainAll()){
            if(answer[1] - answer[0] + 1 > end - start + 1){
                answer[1] = end + 1;
                answer[0] = start + 1;
            }
            erase(gems[start]);
            start++;
        }
        else{
            end++;
            if(end < gems.size()) insert(gems[end]);
        }
        
        
    }
    
    
    return answer;
}
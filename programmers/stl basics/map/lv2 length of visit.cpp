// 방문 길이

#include <string>
#include <map>

using namespace std;

typedef pair<int, int> pii;

pii move(pii origin, char direction){
    pii result = origin;
    switch(direction){
        case 'U':
            result.second++;
            break;
        case 'D':
            result.second--;
            break;
        case 'L':
            result.first--;
            break;
        case 'R':
            result.first++;
            break;
        default:
            break;
    }
    if(result.first < -5) result.first = -5;
    else if(result.first > 5) result.first = 5;
    if(result.second < -5) result.second = -5;
    else if(result.second > 5) result.second = 5;
    
    return result;
}

int solution(string dirs) {
    int answer = 0;
    
    pii origin = {0, 0};
    map<pair<pii, pii>, int> m;
    for(char c : dirs){
        pii bef = origin;
        origin = move(origin, c);
        pii aft = origin;
        
        if(aft != bef && m.find({bef, aft}) == m.end() && m.find({aft, bef}) == m.end()){
            m[{bef, aft}] = 1;
        }
    }
    
    return m.size();
}
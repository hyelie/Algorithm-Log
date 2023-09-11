// 30분

#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int solution(int len, int weight, vector<int> truck_weights) {
    int cur_sum = 0; // 현재 다리 위에 있는 트럭 무게
    queue<pii> curs; //.first : 무게, .second : 들어온 시간 t
    
    // 대기열
    queue<int> waits;
    for(int wait : truck_weights) waits.push(wait);
    
    int t = 1;
    while(1){
        // 다리에서 나가는 경우
        if(!curs.empty() && t >= curs.front().second + len){
            cur_sum -= curs.front().first;
            curs.pop();
        }
        
        // 다리에 진입하는 경우
        if(curs.size() < len && !waits.empty() && cur_sum + waits.front() <= weight){
            curs.push({waits.front(), t});
            cur_sum += waits.front();
            waits.pop();
        }
        
        // 종료조건
        if(waits.size() == 0){
            return t + len;
        }
        
        t++;
    }
    return t;
}
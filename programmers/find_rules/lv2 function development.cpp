// 기능개발

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<pii> q; // .first에는 progresses가, .second에는 speed가 있음.
    
    int size = speeds.size(), completed_work;
    
    for(int i = 0; i<size; i++){
        q.push({progresses[i], speeds[i]});
    }
    
    vector<int> answer;
    
    while(!q.empty()){
        size = q.size();
        while(size--){
            int temp = q.front().first + q.front().second;
            q.push({temp >= 100 ? 100 : temp, q.front().second});
            q.pop();
        }
        
        completed_work = 0;
        while(!q.empty() && q.front().first >= 100){
            completed_work++;
            q.pop();
        }
        if(completed_work != 0)
            answer.push_back(completed_work);
    }

    return answer;
}

// 이렇게 직접 q를 돌려가면서 찾아도 되고

// stack으로도 풀 수 있음. (아래 코드)
// 남은 작업일수를 계산하고
// 예를 들어 5 10 1 1 20 1이라면
// 5 다음에는 10이므로 5만 배포
// 10 다음에는 1 1 20 이므로 20은 배포 못하고, 10 1 1만 배포 가능
// 20 다음에는 1이므로 20 1 같이 배포 가능
// 이렇게 제일 앞에 있는 것의 값보다 더 작은 경우에만 같이 묶을 수 있음

/*vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int size = speeds.size();
    vector<int> left_days(size);
    for(int i = 0; i<size; i++){
        left_days[i] = ceil(((double)100 - (double)progresses[i]) / (double)speeds[i]);
    }
    
    int max_val = left_days[0], max_idx = 0;
    vector<int> answer;
    for(int i = 1; i<=size; i++){
        if(i == size){
            answer.push_back(i - max_idx);
            break;
        }
        if(max_val < left_days[i]){
            max_val = left_days[i];
            answer.push_back(i - max_idx);
            max_idx = i;
        } else{
            continue;
        }
    }
    return answer;
}*/
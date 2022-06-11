// 외벽 점검

#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int INF = 99999;

int solution(int n, vector<int> weak, vector<int> dist) {
    deque<int> weaks(weak.begin(), weak.end());
    sort(dist.begin(), dist.end());
    
    int weaksize = weak.size(), distsize = dist.size();
    
    weaks.push_front(weaks.back()); weaks.pop_back();
    int answer = INF;
    for(int cycle_num = 0; cycle_num<weaksize; cycle_num++){
        weaks.push_back(weaks.front()); weaks.pop_front();

        vector<int> clockwise(weaks.begin(), weaks.end());        
        
        int clockwise_min = clockwise[0];
        for(int i = 0; i<weaksize; i++){
            clockwise[i] -= clockwise_min;
            if(clockwise[i] < 0) clockwise[i] += n;
        } // 시계방향. 제일 첫 지점은 무조건 0으로 두고, 값이 음수면 n 더해주자.
        
        do{
            int friend_num = 0, widx;
            // 현 조합으로 모든 weak 탐색 가불 조사
            for(widx = 0; widx < weaksize; widx++){
                friend_num++;
                if(friend_num > dist.size()){
                    // 만약 friend 수가 너무 크면 불가. false
                    friend_num = 0;
                    break;
                }
                // 현 위치, 현 탐색중인 친구 index를 이용해 어디까지 탐색 가능한지 저장.
                int cur_position = clockwise[widx], cur_range = clockwise[widx] + dist[friend_num-1];
                // 다음 weak 지점이 탐색 가능 -> widx++
                while(widx + 1< weaksize){
                    if(clockwise[widx+1] <= cur_range) widx++;
                    else break;
                }
            }
            // 탐색 불가면 처음부터 다시.
            if(friend_num == 0) continue;
            // 가능하다면 min값 저장
            answer = min(answer, friend_num);
        }while(next_permutation(dist.begin(), dist.end()));   
    }
    
    return answer == INF? -1 : answer;
}

/*
#include <string>
#include <vector>
#include <deque>
#include <algorithm>


using namespace std;

int INF = 99999;

int find_need_friend(vector<int>& weaks, vector<int> dist){
    int answer = INF, weaksize = weaks.size();
    do{
        int friend_num = 0;
        for(int widx = 0; widx < weaksize; widx++){
            friend_num++;
            if(friend_num > dist.size()){
                friend_num = -1;
                break;
            }
            int cur_position = weaks[widx], cur_range = weaks[widx] + dist[friend_num-1];
            while(widx + 1 < weaksize){
                if(weaks[widx+1] <= cur_range) widx++;
                else break;
            }
        }
        if(friend_num == -1) continue;
        answer = min(answer, friend_num);
    }while(next_permutation(dist.begin(), dist.end()));
    if(answer == INF) return -1;
    return answer;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    deque<int> weaks(weak.begin(), weak.end());
    sort(dist.begin(), dist.end());
    
    int weaksize = weak.size(), distsize = dist.size();
    
    weaks.push_front(weaks.back()); weaks.pop_back();
    int answer = INF;
    for(int cycle_num = 0; cycle_num<weaksize; cycle_num++){
        weaks.push_back(weaks.front()); weaks.pop_front();

        vector<int> clockwise(weaks.begin(), weaks.end()), counterclockwise(weaksize);        
        counterclockwise[0] = clockwise[0];
        for(int i = 0; i<weaksize-1; i++){
            counterclockwise[weaksize - i - 1] = clockwise[i+1];
        }
        
        int clockwise_min = clockwise[0], counterclockwise_max = counterclockwise[0];
        for(int i = 0; i<weaksize; i++){
            clockwise[i] -= clockwise_min;
            if(clockwise[i] < 0) clockwise[i] += n;
            counterclockwise[i] = counterclockwise_max - counterclockwise[i];
            if(counterclockwise[i] < 0) counterclockwise[i] += n;
            
        }
        
        int cwiseanswer = find_need_friend(clockwise, dist);
        int ccwiseanswer = find_need_friend(counterclockwise, dist);
        if(cwiseanswer != -1) answer = min(answer, cwiseanswer);
        if(ccwiseanswer != -1) answer = min(answer, ccwiseanswer);    
    }
    
    return answer == INF? -1 : answer;
}*/
/*
brute-force로 ?
총 15개 있고
양쪽으로 2번
각 탐색마다 8!
*/
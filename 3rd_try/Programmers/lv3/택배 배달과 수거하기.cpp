#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int deliveries_last_index = -1; // 가는 길에 줘야 하는 마지막 집 index
    int pickups_last_index = -1; // 오는 길에 받아야 하는 마지막 집 index
    for(int i = n-1; i>=0; i--){
        if(deliveries[i] != 0){
            deliveries_last_index = i;
            break;
        }
    }
    for(int i = n-1; i>=0; i--){
        if(pickups[i] != 0){
            pickups_last_index = i;
            break;
        }
    }
    
    ll answer = 0;
    ll tempcap;
    while(1){
        // 종료 조건
        if(deliveries_last_index < 0 && pickups_last_index < 0) break;
        
        // 0. 1, 2 중 더 먼 것을 더함.
        answer += max(deliveries_last_index + 1, pickups_last_index + 1) * 2; // 시작 지점은 0이므로

        // 1. 가는 길에 줄 수 있는 만큼 최대로 줌.
        tempcap = cap;
        while(deliveries_last_index >= 0 && tempcap > 0){ // 배달할 집이 남았고, 적재량 여유 있는 경우
            if(deliveries[deliveries_last_index] > tempcap){ // 더 해야 하면 그만큼 양만 줄임
                deliveries[deliveries_last_index] -= tempcap;
                tempcap = 0;
            }
            else{ // 끝이면 index--, 순서 중요:
                tempcap -= deliveries[deliveries_last_index]; 
                deliveries[deliveries_last_index] = 0;
                deliveries_last_index--;
                
            }
        }
        while(deliveries_last_index >= 0 && deliveries[deliveries_last_index] == 0){ // 0000인 case
            deliveries_last_index--;
        }
        
        // 2. 오는 길에 최대한 가지고 옴.
        tempcap = cap;
        while(pickups_last_index >= 0 && tempcap > 0){
            if(pickups[pickups_last_index] > tempcap){
                pickups[pickups_last_index] -= tempcap;
                tempcap = 0;
            }
            else{
                tempcap -= pickups[pickups_last_index];
                pickups[pickups_last_index] = 0;
                pickups_last_index--;
            }
        }
        while(pickups_last_index >= 0 && pickups[pickups_last_index] == 0){
            pickups_last_index--;
        }
    }
    
    return answer;
}

/*
멀리 있는 것을 최대한 덜 가야 하니까, 멀리있는 것부터 처리하면 됨.

항상 최대로 들고 간다고 생각하고, 최대로 들고 온다고 생각하자. 
만약 남으면 그만큼 안 들고갔다고 하면 됨. greedy!

n * 50 (각집 최대 개수) / cap만큼 반복문
5,000,000번 -> simulation + greedy.
*/
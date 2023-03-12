#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int lastPickupIdx = n-1, lastDeliverIdx = n-1;
    
    // *** 반례 : 끝부분이 0인 경우에는 안 가도 됨
    while(lastPickupIdx >= 0 && pickups[lastPickupIdx] == 0) lastPickupIdx--;
    while(lastDeliverIdx >= 0 && deliveries[lastDeliverIdx] == 0) lastDeliverIdx--;
    
    long long answer = 0, curDelivery, curPickup;
    
    while(1){
        if(lastPickupIdx < 0 && lastDeliverIdx < 0) break;
        answer += (max(lastPickupIdx, lastDeliverIdx) + 1) * 2;
        
        // 다시 시작
        curPickup = cap;
        while(curPickup >= 0 && lastPickupIdx >= 0){
            if(curPickup >= pickups[lastPickupIdx]){ // 당길 수 있으면 당김
                curPickup -= pickups[lastPickupIdx];
                pickups[lastPickupIdx] = 0;
                lastPickupIdx--;
            }
            else{ // 당기지는 못할 경우 그 양만큼 줄임
                pickups[lastPickupIdx] -= curPickup;
                curPickup = 0;
                break;
            }
        }
        
        curDelivery = cap;
        while(curDelivery >= 0 && lastDeliverIdx >= 0){
            if(curDelivery >= deliveries[lastDeliverIdx]){ 
                curDelivery -= deliveries[lastDeliverIdx];
                deliveries[lastDeliverIdx] = 0;
                lastDeliverIdx--;
            }
            else{ 
                deliveries[lastDeliverIdx] -= curDelivery;
                curDelivery = 0;
                break;
            }
        }
    }
    
    return answer;
}

/*
끝에서부터 하면 되는거같은데. greedy임.
최대로 가져가서 뒤에서부터 배달할 수 있을 때까지 배달하고, 이후 돌아옴
뒤에서부터 가져올 수 있을 만큼 가져오고, 이후 돌아옴.

이 때 [최대로 가져가서 배달할 수 있을 때까지 배달] 한 후에는 cap이 0인 상태
따라서 [뒤에서부터 가져올 수 있을 만큼 가져오고 돌아옴] 할 수 있음.
이 때 둘 중 큰 index만큼 왕복해야 함.(max(i, j) + 1) * 2

반례로 끝부분이 0인 경우는 가지 않아도 되기 때문에 그만큼 당겨줌.

1:16 솔
*/
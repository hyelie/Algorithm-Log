#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int n;
int coin;
set<int> hands;
set<int> graves;

bool can_submit(){
    // 둘 다 손에 있는 경우
    for(int cur : hands){ 
        int target = n - cur + 1;
        if(hands.find(target) != hands.end()){
            hands.erase(cur);
            hands.erase(target);
            return true;
        }
    }
    
    // 하나는 손, 하나는 무덤에
    for(int cur : hands){
        int target = n - cur + 1;
        if(coin >= 1 && graves.find(target) != graves.end()){
            hands.erase(cur);
            graves.erase(target);
            coin--;
            return true;
        }
    }
    
    // 둘 다 무덤에
    for(int cur : graves){
        int target = n - cur + 1;
        if(coin >= 2 && graves.find(target) != graves.end()){
            graves.erase(cur);
            graves.erase(target);
            coin -= 2;
            return true;
        }
    }
    
    return false;
}

int solution(int _coin, vector<int> cards) {
    // init
    n = cards.size();
    coin = _coin;
    for(int i = 0; i<n/3; i++){
        hands.insert(cards[i]);
    }
    
    
    int stage = 1;
    for(int i = n/3; i<n; i += 2, stage++){
        int first = cards[i], second = cards[i+1];
        graves.insert(first); graves.insert(second);
        
        if(!can_submit()) break;
    }
    
    return stage;
}

/*
1. 뽑은 카드 두 장 버리기 (코인 유지)
2. 뽑은 카드 1장 버리고 1장 가져오기
3. 뽑은 카드 2장 가져오기


*/
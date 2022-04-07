// [1차] 캐시

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<string, int> psi;

int solution(int cacheSize, vector<string> cities) {
    vector<psi> cache(cacheSize, {"", 1000000});
    
    int time = 0;
    if(cacheSize == 0) return 5 * cities.size();
    for(string city : cities){
        for(int i = 0; i<city.length(); i++){
            city[i] = tolower(city[i]);
        }
        
        // city가 cache안에 있다면, 해당 city의 참조값을 0으로 둠.
        // 없다면, 참조값이 제일 큰 것의 위치에 넣음.
        // 모든 lru 수치를 1 더함.
        bool isIn = false;
        for(psi &elem : cache){
            if(elem.first == city){
                isIn = true;
                elem.second = 0;
                break;
            }
        }
        
        if(isIn){
            time++;
        } else{
            time += 5;
            int max_idx, max_value = -1;
            for(int i = 0; i<cacheSize; i++){
                if(cache[i].second > max_value){
                    max_value = cache[i].second;
                    max_idx = i;
                }
            }
            cache[max_idx].first = city;
            cache[max_idx].second = 0;
        }
        
        for(int i = 0; i<cacheSize; i++){
            cache[i].second++;
        }
    }
    return time;
    
    
}
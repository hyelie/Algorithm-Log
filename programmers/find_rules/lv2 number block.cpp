// 숫자 블록

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(int i = begin; i<=end; i++){
        if(i == 1){
            answer.push_back(0);
            continue;
        }

        int max_divisor = 1;
        for(int d = 2; d<=sqrt(i); d++){
            if(i % d == 0){
                if(i/d > 10000000) continue;
                max_divisor = max(max_divisor, i/d);
                break;
            }
        }
        answer.push_back(max_divisor);
    }
    
    return answer;
}

// 약수 중 본인을 제외한 가장 큰 수
// 1개당 sqrt(n) * 10000
// 타일은 10000000까지니까 약수가 이거보다 크면 cut해야 함
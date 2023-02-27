#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    string str = to_string(storey);
    reverse(str.begin(), str.end());
    storey = stoi(str);
    
    while(storey != 0){
        int cur = storey % 10; storey /= 10;
        int next = storey % 10;
        
        answer += min(abs(10 - cur), cur);
        if(cur > 5){ // 5보다 크면 한자리 올리는 게 이득
            storey += 1;
        }
        else if(cur < 5){
        }
        else{ // cur == 5
            if(next >= 5) storey += 1;
        }
    }
    
    return answer;
}

/*
자리수 뒤에 있는 게 5보다 크면 한자리 올리고 내리는 게 이득

555는? 14임.
600 : 6
595 : 11
585 12 
575 13
565 14
555 15

1000 : 1
 999 : 1
 995 : 4
 555 : 14
 
2554
2000 + 2
554 : 1000에서 시작하는 게 나음 + 1
436 : +4
36 : +3
6 : 10에서 시작하는 게 나음 +5

3000 : +3
2554 : +4
       




*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    long long cnt = 0, numLL = (long long) num;
    while(1){
        if(cnt >= 500) return -1;
        if(numLL == 1) return cnt;
        
        if(numLL%2) numLL = 3*numLL+1;
        else numLL /= 2;
        
        cnt++;
        cout<<cnt<<endl;
    }
    return cnt>=500 ? -1 : cnt;
}
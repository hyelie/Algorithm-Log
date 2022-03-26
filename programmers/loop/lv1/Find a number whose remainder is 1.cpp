// 나머지가 1이 되는 수 찾기

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for(int i = 1; i<=n; i++){
        if(n % i == 1) return i;
    }
}

/*

n % x = 1이 되는 x를 찾아라
n = ax + 1 (a는 0보다 크거나 같다)

*/
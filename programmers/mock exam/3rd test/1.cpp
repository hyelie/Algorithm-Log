#include <string>
#include <vector>

using namespace std;

int solution(int give, int take, int cur) {
    int answer = 0;

    while(cur >= give){ // 현재 가지고 있는 게 주는 것보다 많으면 줄 수 이씅ㅁ
        int ret = (cur / give) * take; // 돌려받는 것
        answer += ret;
        cur = cur - ((cur / give) * give) + ret; // 현재 개수 = 현재 개수 - 준 것 + 돌려받은 것
    }

    return answer;
}
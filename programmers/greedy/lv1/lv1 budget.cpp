// 예산

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int d_size = d.size(), sum = 0, i = 0;
    for(i = 0; i<d_size; i++){    
        sum += d[i];
        if(sum > budget) break;
    }
    return i;
}

/*

budget : 천만
d.size : 100

정렬해서 앞에서부터 따오는 게 optimal인가?

(오름차순 정렬된) a1, a2, ... an, 그리고 b가 있다고 하자. ai + ... + aj <= b인 i, j가 문제 조건을 만족시키는 optimal value이라고 하자. (i != 1, i < j)
a_i-1 <= a_i <= a_j이기 때문에
a_i-1 + a_i+1 + ... + aj <= ai + ... + aj
또, a_i-1 + a_i + ... + a_j-1 <= a_i-1 + a_i+1 + ... + aj <= ai + ... + aj이 된다.
이렇게 계속 반복해 나가면 어떤 j-i+1인 k에 대해
a1 + ... + ak <= ai + ... + aj가 되는데
그리고 제한조건에서 i != 1이라고 명시했기 때문에
a1 + ... + ak < ai + ... + aj는 자명하다.
이때 ai + ... + aj - (a1 + ... + ak)의 차를 이용해 a_k+1를 넣을 수도 있고(아닐 수도 있다) 넣는 경우 i != 1인 i, j 쌍은 존재하지 않고, 아닌 경우에는 i-j+1은 optimal...
따라서 앞에서부터 세는 게 optimal이다.


*/
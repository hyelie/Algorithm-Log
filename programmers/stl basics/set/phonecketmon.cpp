// 폰켓몬

#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s(nums.begin(), nums.end());
    /*
    for(int num :nums){
        s.insert(num);
    }
    */
    return min(s.size(), nums.size()/2);
}

/*

1번 1
2번 1
3번 2

총 4C2만큼의 경우의 수를 고를 수 있는데
이 때 최대한 다른 포켓몬을 많이 고르고 싶다...고 한다.

입력 1만 -> n^2까지 가능.

만약 set size가 n/2보다 작다 -> 그게 최대임
set size가 n/2보다 크거나 같다 -> n/2가 최대임.



*/
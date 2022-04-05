// 점프와 순간이동

#include <iostream>

using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n){
        ans += n%2;
        n/=2;
    }

    return ans;
}

/*
5 : 101
6 : 110
5000 2진수 -> 1001110001000
*/
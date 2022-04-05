#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int cnt = 0;
    a--; b--;
    while(a != b){
        a/=2; b/=2;
        cnt++;
    }
    
    /*do{
        if(a&1) a++; if(b&1) b++;
        a/=2; b/=2;
        cnt++;
    }while(abs(a-b) != 0);*/
    
    return cnt;
}
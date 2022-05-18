// N으로 표현

#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {    
    vector<set<int>> as(9); // arr[i] : N i개를 사용해서 만들 수 있는 수 리스트
    int originN = N;
    for(int i = 1; i<=8; i++){
        as[i].insert(N);
        N = stoi(to_string(N) + to_string(originN));
    }
    
    for(int i = 1; i<=8; i++){
        for(int front = 1; front < i; front++){
            int back = i - front;
            for(int fn : as[front]){
                for(int bn : as[back]){
                    as[i].insert(fn + bn);
                    as[i].insert(fn - bn);
                    as[i].insert(fn * bn);
                    if(bn != 0) as[i].insert(fn / bn);
                }
            }
        }
        if(as[i].find(number) != as[i].end()) return i;
    }
    return -1;
}

/*

+, -, *, /, 숫자 붙이기
5개의 경우의 수가 가능함

*/
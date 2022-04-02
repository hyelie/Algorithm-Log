// 2개 이하로 다른 비트

#include <string>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<long long> solution(vector<long long> numbers) {
    int size = numbers.size();
    vector<ll> answers(size);
    for(int i = 0; i<size; i++){
        if(numbers[i] & 1){
            ll idx = 1;
            while(numbers[i] & idx){
                idx <<= 1;
            } idx >>= 1;
            answers[i] = numbers[i] + idx;
        } else{
            answers[i] = numbers[i] + 1;
        }
    }
    return answers;
}

// 짝수 : +1하면 됨
// 홀수 : 
// 뒤에서부터 연속되는 1중 제일 앞의 것 idx을 찾아서
// idx-1와 idx를 바꾸면 된다
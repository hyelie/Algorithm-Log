// 다음 큰 숫자

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cntOne(int n){
    int cnt = 0;
    while(n){
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}

int solution(int n) {
    int nOne = cntOne(n);
    while(nOne != cntOne(++n)){
    }
    
    return n;
}

/*

n보다 크고, 2진수로 변환했을 때 1 개수가 같고, 제일 작은 수
1001110

규칙

*/





/*

vector<int> toBinary(int n){
    vector<int> arr;
    while(n!=0){
        arr.push_back(n%2);
        n/=2;
    }
    return arr;
}

int countOne(vector<int> &binary){
    int size = binary.size(), cnt= 0;
    for(int i = 0; i<size; i++){
        if(binary[i] == 1) cnt++;
    }
    return cnt;
}

int toDecimal(vector<int> &binary){
    int two = 1, size = binary.size(), result = 0;
    for(int i = 0; i<size; i++){
        result += binary[i] * two;
        two *= 2;
    }
    return result;
}

int solution(int n) {
    vector<int> nToBinary = toBinary(n);
    int condition = countOne(nToBinary);
    
    while(1){
        vector<int> nextBinary = toBinary(++n);
        int nextCondition = countOne(nextBinary);
        if(condition == nextCondition) break;
    }

    return n;
}*/
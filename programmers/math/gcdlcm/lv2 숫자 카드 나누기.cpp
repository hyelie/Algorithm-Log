#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    // get GCD of A's and B's
    int AGCD = arrayA[0];
    for(int i = 1; i<arrayA.size(); i++){
        AGCD = gcd(AGCD, arrayA[i]);
    }
    
    int BGCD = arrayB[0];
    for(int i = 1; i<arrayB.size(); i++){
        BGCD = gcd(BGCD, arrayB[i]);
    }
        
    bool Adividable = false;
    for(int a : arrayA){
        if(a % BGCD == 0) Adividable = true;
    }
    bool Bdividable = false;
    for(int b : arrayB){
        if(b % AGCD == 0) Bdividable = true;
    }    
    
    int answer = 0;
    if(!Adividable) answer = max(answer, BGCD);
    if(!Bdividable) answer = max(answer, AGCD);
    
    return answer;
}
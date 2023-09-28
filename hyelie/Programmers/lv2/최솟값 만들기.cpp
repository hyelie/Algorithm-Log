#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int answer = 0, len = A.size();
    for(int i = 0; i<len; i++){
        answer += A[i] * B[i];
    }

    return answer;
}
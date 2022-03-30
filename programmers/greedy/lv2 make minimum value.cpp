#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B){
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), less<int>());
    
    int answer = 0, size = A.size();
    for(int i = 0; i<size; i++){
        answer += A[i] * B[i];
    }
    return answer;
    
}














/*
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    int size = A.size();

    priority_queue<int> a;  // max heap
    priority_queue<int, vector<int>, greater<int>> b; // min heap
    
    for(int i = 0;i <size; i++){
        a.push(A[i]);
        b.push(B[i]);
    }
    
    for(int i = 0; i<size; i++){
        answer += a.top() * b.top();
        a.pop(); b.pop();
    }

    return answer;
}*/
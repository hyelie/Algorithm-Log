#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int standard;
bool cmp(vector<int>& a, vector<int>& b){
    if(a[standard-1] == b[standard-1]){
        return a[0] > b[0];
    }
    else return a[standard-1] < b[standard-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    standard = col;
    sort(data.begin(), data.end(), cmp);
    vector<int> xors;
    for(int i = 0; i<data.size(); i++){
        int sum = 0;
        for(int value : data[i]){
            sum += value % (i+1);
        }
        xors.push_back(sum);
    }
    
    int answer = xors[row_begin-1];
    for(int i = row_begin; i<row_end; i++){
        answer ^= xors[i];
    }
    return answer;
}
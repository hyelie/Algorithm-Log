// 쿼드압축 후 개수 세기

#include <string>
#include <vector>

using namespace std;

void div(vector<vector<int>>& arr, vector<int>& answer, int r, int c, int size){
    if(size == 1){
        answer[arr[r][c]]++;
        return;
    }
    
    int base = arr[r][c];
    bool compressable = true;
    for(int i = r; i<r + size; i++){
        for(int j = c; j < c + size; j++){
            if(base != arr[i][j]){
                compressable = false;
            }
        }
    }
    
    if(compressable){
        answer[base]++;
    } else{
        int halfsize = size/2;
        div(arr, answer, r, c, halfsize);
        div(arr, answer, r + halfsize, c, halfsize);
        div(arr, answer, r, c + halfsize, halfsize);
        div(arr, answer, r + halfsize, c + halfsize, halfsize);
    }
    return;
}

vector<int> solution(vector<vector<int>> arr) {    
    vector<int> answer(2, 0);
    div(arr, answer, 0, 0, arr.size());
    return answer;
}

// divide and conquer로 해결 될 듯?
// 십자선 그리고 1~4사분면 4개 파트로 나누면 될듯.
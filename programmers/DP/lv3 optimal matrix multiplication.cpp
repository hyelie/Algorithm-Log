// 최적의 행렬 곱셈

#include <string>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int size = matrix_sizes.size();
    vector<vector<int>> v(size, vector<int>(size, 0)); // v[i][j] : i~j까지 곱 최솟값
    

    
    for(int len = 2; len<=size; len++){
        for(int i = 0; i<size-len+1; i++){
            int j = i + len - 1, min_value = INT_MAX;
            for(int k = i; k<j; k++){
                min_value = min(min_value, v[i][k] + v[k+1][j] + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1]);
            }
            v[i][j] = min_value;
        }
    }
    
    
    // v[i][j] : min(i~k * k+1~j)
    
    return v[0][size-1];
}
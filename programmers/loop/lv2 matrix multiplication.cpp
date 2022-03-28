// 행렬의 곱셈

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int row1 = arr1.size(), col1 = arr1[0].size(); // = row2
    int col2 = arr2[0].size();
    vector<vector<int>> answer(row1, vector<int>(col2, 0));
    
    for(int i =0; i<row1; i++){
        for(int j = 0; j<col2; j++){
            int temp = 0;
            for(int k = 0; k<col1; k++){
                temp += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = temp;
        }
    }
    return answer;
}

// 








/*
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    
    int m = arr1.size();
    int n = arr2.size();
    int l = arr2[0].size();
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<l; j++){
            for(int k = 0; k<n; k++){
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}*/
/*
m * n, n * l
*/
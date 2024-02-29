#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    // init
    int len = triangle.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    dp[0][0] = triangle[0][0];
    for(int i = 1; i<len; i++){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }
    
    // dp
    for(int i = 2; i<len; i++){
        for(int j = 1; j<=i; j++){
            dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    
    return *max_element(dp[len-1].begin(), dp[len-1].end());
}









// // 정수 삼각형

// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int solution(vector<vector<int>> triangle) {
    
//     int height = triangle.size();
//     for(int h = 1; h<height; h++){
//         triangle[h][0] += triangle[h-1][0];
//         triangle[h][h] += triangle[h-1][h-1];
//         for(int r = 1; r<h; r++){
//             triangle[h][r] += max(triangle[h-1][r-1], triangle[h-1][r]);
//         }
//     }
//     return *max_element(triangle[height-1].begin(), triangle[height-1].end());
// }








// /*
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// int solution(vector<vector<int>> triangle) {
//     int answer = 0;
    
//     int height = triangle.size();
//     for(int i = 1; i<height; i++){
//         triangle[i][0] += triangle[i-1][0];
//         triangle[i][triangle[i].size()-1] += triangle[i-1][triangle[i-1].size()-1];
//         for(int j = 1; j<triangle[i].size()-1; j++){
//             triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
//         }
//     }

//     return *max_element(triangle[height-1].begin(), triangle[height-1].end());
 
// }
// */
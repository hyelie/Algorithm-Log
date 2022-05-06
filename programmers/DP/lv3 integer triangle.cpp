// 정수 삼각형

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    
    int height = triangle.size();
    for(int h = 1; h<height; h++){
        triangle[h][0] += triangle[h-1][0];
        triangle[h][h] += triangle[h-1][h-1];
        for(int r = 1; r<h; r++){
            triangle[h][r] += max(triangle[h-1][r-1], triangle[h-1][r]);
        }
    }
    return *max_element(triangle[height-1].begin(), triangle[height-1].end());
}

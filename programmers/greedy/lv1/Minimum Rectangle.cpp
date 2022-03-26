// 최소직사각형

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& a, int&b){
    int temp = a;
    a = b;
    b = temp;
}

int solution(vector<vector<int>> sizes) {
    
    int max_width = -1, max_length = -1;
    for(vector<int> v : sizes){
        if(v[0] < v[1]) swap(v[0], v[1]);
        max_width = max(max_width, v[0]);
        max_length = max(max_length, v[1]);
    }
    
    return max_width * max_length;
}
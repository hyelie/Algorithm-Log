// 평균 구하기

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum = 0;
    for(int element : arr){
        sum += element;
    }
    
    
    double answer = (double) sum / (double)arr.size();
    return answer;
}
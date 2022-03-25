#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int elem : arr){
        if(elem % divisor == 0) answer.push_back(elem);
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}
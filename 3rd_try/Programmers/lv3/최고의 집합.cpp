#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s) return {-1};
    
    int q = s / n;
    vector<int> answer(n, q);
    int r = s - q * n;
    
    if(r > 0){
        for(int &elem : answer){
            elem++;
            r--;
            if(r == 0) break;
        }    
    }
    
    sort(answer.begin(), answer.end(), less<int>());
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<double> solution(int k, vector<vector<int>> ranges) {
    // areas[i] : i-1부터 i까지 정적분 결과 * 2
    vector<ll> areas;
    areas.push_back(0);
    while(k != 1){
        int prevk = k;
        k = k & 1 ? 3*k + 1 : k/2;
        
        int sum = prevk + k;
        areas.push_back(sum);
    }
    
    // areas[i] : 0부터 i까지 정적분 결과
    for(int i = 1; i<areas.size(); i++){
        areas[i] += areas[i-1];
    }
    
    vector<double> answer;
    for(vector<int> range : ranges){
        int start = range[0], end = areas.size() - 1 + range[1];
        if(start > end) answer.push_back(-1);
        else answer.push_back((double)(areas[end] - areas[start]) / 2);
    }
    return answer;
}
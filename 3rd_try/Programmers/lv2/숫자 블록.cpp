#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int limit = 10000000;

int get_max_divisor(int num){
    if(num == 1) return 0;
    int max_divisor = 1;
    for(int i = 2; i<=sqrt(num); i++){
        if(num % i == 0) {
            if(i <= limit && i != num) max_divisor = max(max_divisor, i);
            if(num/i <= limit && num/i != num) max_divisor = max(max_divisor, num/i);
        }
    }
    return max_divisor;
}

vector<int> solution(long long  begin, long long end) {
    vector<int> answer;
    
    for(int i = begin; i<=end; i++){
        answer.push_back(get_max_divisor(i));
    }
    
    return answer;
}
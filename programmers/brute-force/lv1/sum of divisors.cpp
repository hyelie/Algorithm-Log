#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum_divisors = 0;
    for(int i = 1; i<=n; i++){
        if(n%i == 0) sum_divisors += i;
    }

    return sum_divisors;
}
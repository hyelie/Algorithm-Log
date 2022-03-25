#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 1백만 -> O(nlogn)

int solution(int n) {
    int max_value = n;
    vector<bool> isPrime(n+1, true);
    vector<int> primes;
    
    for(int i = 2; i<=n; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j = 2*i; j<=n; j += i){
            isPrime[j] = false;
        }
    }

    return primes.size();
}
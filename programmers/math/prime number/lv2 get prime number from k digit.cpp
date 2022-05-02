// k진수에서 소수 개수 구하기

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

typedef long long ll;

string changeDigit(int n, int k){
    string result = "";
    while(n != 0){
        result += to_string(n%k);
        n /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}

int solution(int n, int k) {
    string number = changeDigit(n, k);
    
    ll max_value = -1;
    vector<ll> v;
    istringstream iss(number);
    string buffer;
    while(getline(iss, buffer, '0')){
        if(buffer == "") continue;
        v.push_back(stoll(buffer));
        max_value = max(max_value, stoll(buffer));
    }
    
    /*// 체
    vector<bool> isPrime(max_value + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i<=sqrt(max_value); i++){
        if(isPrime[i]){
            for(ll j = i * i; j<=max_value; j += i){
                isPrime[j] = false;
            }    
        }  
    }
    
    int cnt = 0;
    for(int i : v){
        if(isPrime[i]) cnt++;
    }*/
    
    int cnt = 0;
    bool flag;
    for(ll n : v){
        flag = true;
        for(ll i = 2; i<=sqrt(n); i++){
            if(n % i == 0) flag = false;
        }
        if(n == 1) flag = false;
        if(flag) cnt++;
    }
    
    return cnt;
}

// 수를 k진수로 바꾸고, 0 사이에 있는 모든 수를 가져오고, 이게 소수인지 판정하면 되겠군.
// 수가 너무 커서 오류가 나는 경우가 있음. 따라서 체를 사용하지 말고 소수 판정을 사용하자. sqrt(n)
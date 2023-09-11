#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <cmath>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below

// 1000000000000
int INF = 1e7+1;
//int INF = 312;
vector<bool> isPrime(INF+1, true);
vector<int> primes;
int psize;
//vector<ll> psum;
void getPrime(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i<=sqrt(INF); i++){
        if(isPrime[i]){
            for(int j = i*i; j<=INF; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i = 2; i<INF; i++){
        if(isPrime[i]) primes.push_back(i);
    }
    psize = primes.size();

    //cout<<primes.size();
    // psum.resize(primes.size());
    // psum[0] = primes[0];
    // for(int i = 1; i<primes.size(); i++){
    //     psum[i] = primes[i] + psum[i-1];
    // }
    // cout<<psum[primes.size()-1]; // 3조정도가 max값
    // psum[i] - psum[j] = j+1부터 i까지 sum
}

int solve(){
	int m; cin>>m;
    vector<int> arr(m);
    for(int i = 0; i<m; i++) cin>>arr[i];
//    sort(arr.begin(), arr.end(), less<int>());

    int cnt = 0;
    map<int, int> mapper;
    for(int l : arr){
        // sliding window init
        int sum = 0;
        for(int i = 0; i<l; i++){
            sum += primes[i];
        }
        if(sum > INF) break;
        if(isPrime[sum] && (mapper[sum] == cnt || mapper[sum] == 0)) mapper[sum]++;

        // slide to the end
        for(int i = l; i<psize - l; i++){
            sum += primes[i] - primes[i-l];
            if(sum > INF) break;
            if(isPrime[sum] && (mapper[sum] == cnt || mapper[sum] == 0)) mapper[sum]++;
        }

        cnt++;
    }
    
    for(auto const &p : mapper){
        if(p.second == m) return p.first;
    }

    /*
    for all m
        1. arr[0]으로 합친 게 소수인지 확인한다.
            - 소수이면 다른 arr[i]에 대해 같은 값인지 확인한다.
                - 같으면 계속.
                - 다르면 시작 index를 1 늘리고, 1번으로 감.

    */

    return 0;
}

//////////////////////

int main(void) {
	// cin.tie(0);
	// cout.tie(0);
	// std::ios_base::sync_with_stdio(0);
	
	// number of test cases
    getPrime();
    
	int t; cin>>t;
    for(int i = 1; i<=t; i++){
        cout<<"Senario "<<i<<": \n";
        cout<<solve()<<"\n";
    }

	return 0;
}
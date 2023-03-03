#include <string>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

long long solution(vector<int> sequence) {
    int n = sequence.size();
    ll answer = INT_MIN;
    vector<ll> s1(sequence.begin(), sequence.end()), s2(sequence.begin(), sequence.end());
    for(int i = 0; i<n; i+= 2){
        s1[i] *= -1;
    }
    vector<ll> dp1(n, INT_MIN);
    dp1[0] = s1[0];
    answer = max(dp1[0], answer);
    for(int i = 1; i<n; i++){
        dp1[i] = max(dp1[i-1] + s1[i], s1[i]);
        answer = max(dp1[i], answer);
    }
    
    
    for(int i = 1; i<n; i+= 2){
        s2[i] *= -1;
    }
    vector<ll> dp2(n, INT_MIN);
    dp2[0] = s2[0];
    answer = max(dp2[0], answer);
    for(int i = 1; i<n; i++){
        dp2[i] = max(dp2[i-1] + s2[i], s2[i]);
        answer = max(dp2[i], answer);
    }
    
    return answer;
}
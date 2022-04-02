// 소수 찾기

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

void DFS(int cur_depth, int max_depth, vector<bool> &is_used, vector<int>& numbers, set<int>& s, string cur_str){
    if(cur_depth == max_depth){
        s.insert(stoi(cur_str));
        return;
    } else{
        int size = numbers.size();
        for(int i = 0; i<size; i++){
            if(is_used[i]) continue;
            else{
                is_used[i] = true;
                DFS(cur_depth+1, max_depth, is_used, numbers, s, cur_str + to_string(numbers[i]));
                is_used[i] = false;
            }
        }
    }
}

int solution(string numbers) {
    int size = numbers.size();
    vector<int> nums(size);
    for(int i = 0; i<size; i++){
        nums[i] = numbers[i] - '0';
    }
    
    vector<bool> is_used(size, false);
    set<int> candidates; // 만들 수 있는 모든 숫자들
    for(int i = 0; i<size; i++){
        DFS(i, size, is_used, nums, candidates, "");
    }    
    
    ll max_num = 10000001;
    vector<bool> isPrime(max_num, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i<sqrt(max_num); i++){
        if(isPrime[i]){
            for(ll j = i * i; j < max_num; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    vector<int> answer;
    for(int elem : candidates){
        if(isPrime[elem]) answer.push_back(elem);
    }
    return answer.size();
}
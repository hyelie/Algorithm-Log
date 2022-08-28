//0~9 전수탐색 이후 조건에 맞는 것 뽑기

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

void solve(){
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> final = {"six", "seven", "nine", "twelve", "sixteen", "twenty", "seventy"};
    set<char> charset; // 문자들을 담을 set
    for(string strs : final){
        for(char c : strs) charset.insert(c);
    }
    vector<int> mapper(26, -1); // alphabet - index mapper
    int cnt = 0;
    mapper['s'-'a'] = cnt++; // s, n, t는 special case, 0이 안 들어가
    mapper['n'-'a'] = cnt++;
    mapper['t' - 'a'] = cnt++;
    charset.erase('s'); charset.erase('n'); charset.erase('t');
    for(char elem : charset){
        mapper[elem - 'a'] = cnt++;
    }
    vector<int> nums(7); // 각 string의 숫자
    do{
        if(arr[0] == 0 || arr[1] == 0 || arr[2] == 0) continue;
        // SIX + SEVEN+NINE+TWELVE+SIXTEEN+TWENTY=SEVENTY
        for(int i = 0; i<7; i++){
            int mul = 1, ans = 0;
            for(int j = final[i].size()-1; j>=0; j--){
                ans += mul * arr[mapper[final[i][j]-'a']];
                mul *= 10;
            }
            nums[i] = ans;
        }
        if(nums[0] + nums[1] + nums[2] + nums[3] + nums[4] + nums[5] == nums[6]){
            cout<<"s n t ";
            for(char elem : charset) cout<<elem<<' ';
            cout<<endl;
            for(int elem : arr) cout<<elem<<' ';
            break;
        }
    }while(next_permutation(arr.begin(), arr.end()));
    
}


//////////////////////


int main(void) {

cin.tie(0);

cout.tie(0);

std::ios_base::sync_with_stdio(0);


solve();


return 0;

}
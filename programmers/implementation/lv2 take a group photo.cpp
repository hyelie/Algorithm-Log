// 단체사진 찍기

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, vector<string> data) {
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    int cnt = 0;
    
    do{
        bool isSatisfy = true;
        for(string condition : data){
            int dist = abs(find(friends.begin(), friends.end(), condition[0]) - find(friends.begin(), friends.end(), condition[2])) - 1;
            
            if(condition[3] == '=' && dist != condition[4] - '0'){
                isSatisfy = false;
                break;
            }else if(condition[3] == '>' && dist <= condition[4] - '0'){
                isSatisfy = false;
                break;
            }else if(condition[3] == '<' && dist >= condition[4] - '0'){
                isSatisfy = false;
                break;
            }
        }
        if(isSatisfy) cnt++;
    }while(next_permutation(friends.begin(), friends.end()));
    
    return cnt;
}
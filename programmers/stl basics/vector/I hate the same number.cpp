#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    /*vector<int> answer; answer.push_back(arr[0]);
    int arr_size = arr.size();
    
    for(int i = 1; i<arr_size; i++){
        if(answer[answer.size()-1] != arr[i]) answer.push_back(arr[i]);
        
    }

    return answer;*/
    
    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

/* 5백만 -> nlogn으로 품. */
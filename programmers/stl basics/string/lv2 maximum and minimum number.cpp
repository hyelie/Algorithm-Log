// 최댓값과 최솟값

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) {
    vector<int> v;
    int length = s.length();
    string temp = "";
    for(int i = 0; i<=length; i++){
        if(i == length || s[i] == ' '){
            v.push_back(stoi(temp));
            temp = "";
        }
        else{
            temp +=s[i];
        }
    }
    

    
    temp += to_string(*min_element(v.begin(), v.end()));
    temp += " ";
    temp += to_string(*max_element(v.begin(), v.end()));
    
    return temp;
}

    
    






/*
string solution(string s) {
    vector<int> arr;

    int prevSpace = 0, curSpace = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            curSpace = i;
            arr.push_back(stoi(s.substr(prevSpace, curSpace - prevSpace)));
            prevSpace = i;
        }
    }
    arr.push_back(stoi(s.substr(prevSpace, s.size() - prevSpace)));

    sort(arr.begin(), arr.end());




    string answer = "";

    answer = answer + to_string(arr[0]) + ' ' + to_string(arr[arr.size() - 1]);
    return answer;
}*/
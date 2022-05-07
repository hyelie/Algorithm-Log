// 전화번호 목록

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    int size = phone_book.size();
    for(int i = 1; i < size; i++){
        if(phone_book[i].length() > phone_book[i-1].length() && phone_book[i].substr(0, phone_book[i-1].length()) == phone_book[i-1]) return false;
    }
    return true;
}*/

bool solution(vector<string> phone_book) {
    unordered_map<string, int> um;
    
    for(string number : phone_book){
        um[number] = 1;
    }
    
    for(string number : phone_book){
        for(int i = 0; i<number.length()-1; i++){
            cout<<temp<<endl;
            if(um[temp] == 1) return false;
        }
    }
    return true;
    
}
// 이중우선순위큐

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <set>

using namespace std;

typedef multiset<int>::iterator msiter;

msiter getMsiter(multiset<int> & ms, int n){
    if(n == -1){
        return ms.begin();
    }else{
        msiter temp = ms.end(); temp--;
        return temp;
    }
}

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    
    istringstream iss;
    char operation; int n;
    for(string s : operations){
        iss.clear(); iss.str(s);
        iss >> operation >> n;
        
        if(operation == 'I'){
            ms.insert(n);
        } else{
            if(ms.empty()) continue;
            ms.erase(getMsiter(ms, n));
        }
    }
    
    if(ms.empty())return {0, 0};
    else return {*getMsiter(ms, 1), *getMsiter(ms, -1)};
}
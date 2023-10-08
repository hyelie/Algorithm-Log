// 12분에 다 품.
/*
nlogn 알고리즘의 경우, 5백만까지 커버할 수 있음.
최대/최소값을 동시에 nlogn으로 처리해야 하기 때문에 map을 사용했음.
알아둬야 할 것은,
1. map iterator에 접근하는 방법. begin().first로 접근하는 게 아니라 begin()->first로 접근한다.
.first는 key, .second는 value
2. rbegin(). 
3. istringstream으로 정해져 있는 input 받는 방법

*/

#include <set>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

map<int, int> m;

void insertIntoQueue(int n){
    m[n]++;
}

void removeMax(){
    int number = m.rbegin()->first, count = m.rbegin()->second;
    if(count == 1) m.erase(number);
    else m[number]--;
}

void removeMin(){
    int number = m.begin()->first, count = m.begin()->second;
    if(count == 1 || count == 0) m.erase(number);
    else m[number]--;
}
vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que;

    string sub;

    for(auto s : arguments) {
        sub =s.substr(0, 2);
        if(sub=="I ") que.insert(stoi(s.substr(2,s.length()-2))); 
        else if(s.substr(2,1)=="1"&&que.size()>0) { que.erase(--que.end()); }
        else if(que.size()>0) { que.erase(que.begin()); }
    }

    if(que.size()==0) { answer.push_back(0); answer.push_back(0); }
    else { 
       answer.push_back(*que.rbegin()); 
        answer.push_back(*que.begin());
    }

    return answer;
}
/*
input이 1백만 -> O(n)으로 처리해야 함
2^10 = 1000
1000000
2^20 = 1000000

20000000
1백만에 O(nlogn) - OK
*/
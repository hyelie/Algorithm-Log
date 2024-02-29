#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

multiset<int> ms;
typedef multiset<int>::iterator msiter;
void operate(string command, int number){
    if(command == "I"){
        ms.insert(number);
        return;
    }
    
    if(ms.empty()) return;
    
    if(number == 1){
        auto iter = ms.end(); iter--;
        ms.erase(iter);
        return;
    }
    
    if(number == -1){
        ms.erase(ms.begin());
        return;
    }
}

vector<int> solution(vector<string> operations) {
    for(string operation : operations){
        istringstream iss(operation);
        string command;
        int number;
        iss >> command >>number;
        operate(command, number);
    }
    
    if(ms.empty()) return {0, 0};
    return {*ms.rbegin(), *ms.begin()};
}

// // 이중우선순위큐

// #include <string>
// #include <vector>
// #include <iostream>
// #include <queue>
// #include <sstream>
// #include <set>

// using namespace std;

// typedef multiset<int>::iterator msiter;

// msiter getMsiter(multiset<int> & ms, int n){
//     if(n == -1){
//         return ms.begin();
//     }else{
//         msiter temp = ms.end(); temp--;
//         return temp;
//     }
// }

// vector<int> solution(vector<string> operations) {
//     multiset<int> ms;
    
//     istringstream iss;
//     char operation; int n;
//     for(string s : operations){
//         iss.clear(); iss.str(s);
//         iss >> operation >> n;
        
//         if(operation == 'I'){
//             ms.insert(n);
//         } else{
//             if(ms.empty()) continue;
//             ms.erase(getMsiter(ms, n));
//         }
//     }
    
//     if(ms.empty())return {0, 0};
//     else return {*getMsiter(ms, 1), *getMsiter(ms, -1)};
// }



// /*#include <string>
// #include <sstream>
// #include <set>
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> solution(vector<string> operations) {
    
//     // 문자열 입력
//     //stringstream ss;
//     //ss.str(operations[i]); char op; int num; ss>>op>>num;
    
//     multiset<int> s;
//     multiset<int>::iterator iter;
    
    
//     int oplen = operations.size();
    
//     stringstream ss;
//     char op; int num; 
//     for(int i = 0; i<oplen; i++){
//         ss.str(operations[i]); ss>>op>>num;
//         if(op=='I'){
//             s.insert(num);
//         }
//         else{
//             if(!s.empty()){
//                 if(num == -1){
//                     iter = s.begin();
//                     s.erase(iter);
//                 }
//                 else if(num == 1){
//                     iter = s.end();
//                     iter--;
//                     s.erase(iter);
//                 }
//             }
            
//         }
//         ss.clear();
//     }
    

    
//     vector<int> answer(2);
//     if(s.size() == 0) {
//         answer[0] = answer[1] = 0;
//     }
//     else if(s.size()==1){
//         answer[0] = answer[1] = *(s.begin());
//     }
//     else{
//         iter = s.end(); iter--;
//         answer[0] = *iter;
//         answer[1] = *s.begin();
//     }

//     return answer;
// }

// // 썡으로 다 비교하면 1,000,000 백만 -> nlogn으로 무조건 풀어야 함.
// // 처음에는 pq 2개로 쓰고, 각 pq에서 삭제할랬는데 이렇게 풀면 안됨 왤까?*/
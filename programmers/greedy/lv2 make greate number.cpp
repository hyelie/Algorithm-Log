// 큰 수 만들기

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int delete_count = 0;
    string::iterator iter;
    bool isDelete = false;
    
    while(k--){
        isDelete = false;
        for(iter = number.begin(); iter != number.end()-1; iter++){
            if(*iter < *(iter+1)){
                number.erase(iter);
                delete_count++;
                isDelete = true;
                break;
            }
        }
        if(isDelete == false){
            break;
        }
        
    }
    
    k++; // isDelete가 false인 경우에는 그... 삭제 하지 않았는데 k--하니까 이렇게 함.
    while(k-- > 0){
        number.erase(min_element(number.begin(), number.end()));
    }
    
    
    return number;
    
}




/*string solution(string number, int k) {
    
    vector<char> v;
    for (auto c:number){
        v.push_back(c);
    }
    
    vector<char>::iterator iter;
    int k_iter = k;
    while(k_iter--){
        bool isDelete = false;
        for(iter = v.begin(); iter != v.end()-1; iter++){
            if(*iter < *(iter+1)){
                isDelete = true;
                v.erase(iter);
                break;
            }
        }
        if(!isDelete){
            v.erase(iter);
        }
    }
    
    string answer = "";
    for(int i = 0; i<v.size(); i++){
        answer.push_back(v[i]);
    }
    return answer;
}*/

// 앞에서  젤 작은 걸 뺌. 같은 수라면 앞에 있는 걸 뺌
// k개의 수에서 오름차인 것 중 앞에 있는 수를 뺌
// 4177252841
// 477252841
// 77252841
// 7752841
// 775841
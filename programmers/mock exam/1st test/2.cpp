#include <string>
#include <map>
#include <vector>

using namespace std;

bool allsale(vector<int>&number, vector<int>&want_numbers){
    for(int i = 0; i<number.size(); i++){
        if(number[i] <= want_numbers[i]) continue;
        else return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    vector<int> want_numbers(number.size(), 0); // want_number[i] : idx에 해당하는 제품 재고
    map<string, int> m; // m[str] : string에 해당하는 제품의 idx
    for(int i = 0; i<want.size(); i++){
        m[want[i]] = i;
    }

    // two-pointer 초기값 설정
    for(int i = 0; i<10; i++){
        if(m.find(discount[i]) == m.end()) continue;
        want_numbers[m[discount[i]]]++;
    }

    int answer = 0;
    if(allsale(number, want_numbers)) answer++;
    for(int i = 10; i<discount.size(); i++){
        if(m.find(discount[i-10]) != m.end()){ // 10일 전 것은 현재 장바구니에서 뺌
            want_numbers[m[discount[i-10]]]--;
        }
        if(m.find(discount[i]) != m.end()){ // 추가할 것 추가
            want_numbers[m[discount[i]]]++;
        }
        if(allsale(number, want_numbers)) answer++; // 조건 맞으면 ++
    }

    return answer;
}
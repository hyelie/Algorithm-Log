#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> um;
    for(vector<string> elem : clothes){
        if(um.find(elem[1]) == um.end()){
            um[elem[1]] = 1;
        } else{
            um[elem[1]]++;
        }
    }
    
    unordered_map<string, int>::iterator iter;
    int answer = 1;
    for(iter = um.begin(); iter != um.end(); iter++){
        answer *= (iter->second + 1);
    }
    return answer -1;
}









/*

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string, int> m;
    
    int n = clothes.size();
    // 삽입에 O(n)
    for(int i = 0; i<n; i++){
        if(m.find(clothes[i][1]) == m.end()){
            m[clothes[i][1]] = 1;
        }
        else{
            m[clothes[i][1]]++;
        }
    }
    
    // 의상 수 1~30
    
    
    int answer = 0;
    int temp = 1;
    
    unordered_map<string, int>::iterator m_iter;
    
    for(m_iter = m.begin(); m_iter != m.end(); m_iter++){
        temp *= (m_iter->second+1);
    }
    
    return temp-1;
}
*/
// [의상 이름, 의상 종류]
// A의상이 a개
// B의상이 b개
// C의상이 c개
// D의상이 d개
// ... 일 때
// 1개 : a+b+c+d - 전체 중 1개 고르는 거
// 2개 : a*b + a*c + a*d + b*c + b*d + c*d - nC2만큼의 항의 개수, 각 항은 
// 3개 : a*b*c + a*b*d + a*c*d
// 4개 : a*b*c*d
// ...

// 인데, 아무것도 안 입는 경우 제외, A의상을 입는 경우의 수 : a+1(안입는 경우도 포함), B의상을 입는 경우의 수 : b+1(안입는 경우도 포함)
// 다단계 칫솔 판매

#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> name_idx_mapping;

void DFS(string cur, int money, vector<string>& referral, vector<int>& result){
    if(cur == "-" || money == 0) return;
    int idx = name_idx_mapping[cur];
    int temp = money - money/10;
    result[idx] += temp;
    money /= 10;
    DFS(referral[idx], money, referral, result);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> result(enroll.size(), 0);
    for(int i = 0; i<enroll.size(); i++){
        name_idx_mapping[enroll[i]] = i;
    }
    for(int i = 0; i<seller.size(); i++){
        DFS(seller[i], amount[i] * 100, referral, result);
    }
    
    return result;
}
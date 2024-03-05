#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> a) {
    // early return
    int len = a.size();
    if(len <= 2) return len;
    
    // cal
    set<int> left;
    set<int> right;
    left.insert(a[0]);
    for(int i = 2; i<len; i++) right.insert(a[i]);
    
    int answer = 2; // 양 끝쪽 것은 무조건 뽑기 가능
    for(int i = 1; i<len-1; i++){
        int left_min = *left.begin(), right_min = *right.begin();
        
        if(left_min < a[i] && right_min < a[i]){
            left.insert(a[i]);
            right.erase(a[i]);
            continue;
        }
        else{
            left.insert(a[i]);
            right.erase(a[i]);
            answer++;
        }
        
        
        
    }
    
    return answer;
}

int solution(vector<int> a) {
    // early return
    int len = a.size();
    if(len <= 2) return len;
    
    // memo
    int INF = 1e9 + 1;
    vector<int> l(len), r(len);
    // l[i] : i 왼쪽에 있는 값들 중 최소값
    l[0] = INF;
    for(int i = 1; i<len; i++){
        l[i] = min(a[i-1], l[i-1]);
    }
    
    // r[i] : i 오른쪽에 있는 값들 중 최소값
    r[len-1] = INF;
    for(int i = len-2; i>=0; i--){
        r[i] = min(a[i+1], r[i+1]);
    }
    
    int answer = 0; // 양 끝쪽 것은 무조건 뽑기 가능
    for(int i = 0; i<len; i++){        
        if(l[i] < a[i] && r[i] < a[i]) continue;
        answer++;
    }
    
    return answer;
}

/*
greedy.
for all i, 왼쪽에 더 작은거 있는지 + 오른쪽에 더 작은거 있는지
*/
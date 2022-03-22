#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 체육복 개수를 배열로 저장
    vector<int> suit_num(n, 1);

    for(int lost_num : lost)
        suit_num[lost_num-1]--;
    for(int reserve_num : reserve)
        suit_num[reserve_num-1]++;

    
    // 2개 있는 사람이 나눠주는 걸 기준으로 생각하면 -> 방향에 따라 최적해가 나올 수도, 아닐 수도 있다.
    // 그래서 어려워 했는데 이렇게 생각하지 말고
    
    // 0개 있는 사람이 빌린다고 생각하면 풀리는 것 같다.
    // 탐색을 앞에서부터 진행할 거니까, 0인 사람이 앞사람에게 물어 봤을 때
        // 0인 경우 -> 어차피 못빌려줌 -> 뒷사람에게 물어보면 된다.
        // 1인 경우 -> 앞사람에게 줬을 수도 있다(이 경우에는 '앞 사람'이 앞으로 주나 뒤로 주나 최종값은 동일해진다) 처음부터 1개였을 수도 있고.
        // 2인 경우 -> 앞사람에게 빌려오면 된다. 이렇게 결론지어지는 이유는 앞사람이 2인 경우는, 앞앞사람에게 줄 필요가 없었기 떄문이다. 만약 0인 사람의 뒷사람에게 빌리는 경우 그 뒤가 어떻게 될지 모르기 때문에 어지러워지는데, 앞사람에게 빌리는 경우 앞사람의 자원은 잉여자원이기 때문에 괜찮다.
    
    // 즉, 탐색을 앞에서부터 진행하기 때문에 앞사람에게 먼저 물어보고,
    // 없다면 뒷사람에게 빌려오면 된다.
    
    int answer = 0;
    
    if(suit_num[0] == 0 && suit_num[1] == 2){
        suit_num[0]++; suit_num[1]--;
    }
    for(int i = 1; i<n-1; i++){
        if(suit_num[i] == 0){
            if(suit_num[i-1] == 2){
                suit_num[i-1]--; suit_num[i]++;
            }
            else if(suit_num[i+1] == 2){
                suit_num[i+1]--; suit_num[i]++;
            }
            else{
                continue;
            }
        }
    }
    if(suit_num[n-1] == 0 && suit_num[n-2] == 2){
        suit_num[n-1]++; suit_num[n-2]--;
    }
    
    for(int i = 0; i<n; i++){
        answer += suit_num[i] >= 1 ? 1 : 0;
    }
    
    return answer;
}
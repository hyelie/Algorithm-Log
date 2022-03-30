#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(vector<int> prices) {
    //priority_queue<pii, vector<pii>, less<pii>> pq; // {price, idx}
    stack<pii> pq;
    
    
    int size =prices.size();
    pii temp;
    vector<int> answer(size, 0);
    for(int i = 0; i<size; i++){
        /*if(pq.empty() || pq.top().first <= prices[i]){
            pq.push({prices[i], i});
        } else{
            while(!pq.empty() && pq.top().first > prices[i]){
                temp = pq.top();
                answer[temp.second] = i - temp.second;
                pq.pop();
            }
            pq.push({prices[i], i});
        }*/
        
        while(!pq.empty() && pq.top().first > prices[i]){
            temp = pq.top();
            answer[temp.second] = i - temp.second;
            pq.pop();
        }
        pq.push({prices[i], i});
    }
    
    while(!pq.empty()){
        temp = pq.top();
        answer[temp.second] = size - 1 - temp.second;
        pq.pop();
    }
 
    return answer;
}

/*

앞에서부터 하나씩 pq에 넣음. (pq의 top은 현재 있는 것들 중 최댓값)
prices[i] < pq.top()이라면 가격이 떨어졌다는 것 -> 이에 따른 처리를 해 주면 됨
prices[i] >= pq.top()이라면 가격이 떨어지지 않았다는 것

*/
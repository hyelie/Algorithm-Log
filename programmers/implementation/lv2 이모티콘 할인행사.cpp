#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> discounts(7); // discounts[i] : emoticon i의 할인율
vector<vector<int>> Users;
vector<int> Emoticons;
vector<int> ratio = {10, 20, 30, 40};
int userSize, emoticonSize;
int maxJoins = -1, maxProfit = -1;

int getDiscountPrice(int originPrice, int discountRatio){
    // price max : 1,000,000 / 따라서 100 더 곱해도 int 범위 안
    return originPrice * (100 - discountRatio) / 100;
}

void permutation(int depth, int max_depth){
    if(depth == max_depth){
        int numJoins = 0;
        int sumProfit = 0;
        for(vector<int> User : Users){ // for all user
            int payPrice = 0;
            for(int i = 0; i<emoticonSize; i++){ // for all emoticons
                if(User[0] <= discounts[i]){ // 할인율 더 큰 경우 삼
                    payPrice += getDiscountPrice(Emoticons[i], discounts[i]);
                }
            }
            if(payPrice >= User[1]) numJoins++; // 결제금이 기준 이상인 경우 join
            else sumProfit += payPrice;
        }
        
        if(numJoins > maxJoins){
            maxJoins = numJoins;
            maxProfit = sumProfit;
        }
        else if(numJoins == maxJoins){
            maxProfit = max(maxProfit, sumProfit);
        }
        /*if(numJoins >= maxJoins){ // *** 실수 : 1번 조건과 2번 조건을 혼용했음
            maxJoins = numJoins;
            maxProfit = max(maxProfit, sumProfit);
        }*/
        return;
    }
    
    for(int i = 0; i<ratio.size(); i++){
        discounts[depth] = ratio[i];
        permutation(depth+1, max_depth);
    }
}

// users[i] : [비율, 가격] / 비율보다 큰 할인율 사고 / 가격보다 크면 플러스 가입 / size 100
// emoticions[i] : 정가, 100 배수 / 10, 20, 30, 40 할인 가능
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    userSize = users.size();
    emoticonSize = emoticons.size();
    Users = users;
    Emoticons = emoticons;
    
    permutation(0, emoticonSize);

    return {maxJoins, maxProfit};
}

/*
4^7 = 2^14 = 16 * 1000 = 16000
사용자가 100이니까
1,600,000 2백만 Solve

중복순열
구현 문제

1:38 솔
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int sales_available[4] = {10, 20, 30, 40};
vector<int> sales(7, 0); // sales[i] : emoticons[i]의 세일 %.
vector<vector<int>> all_sales;
int num_emoticons;

// 모든 이모티콘의 가능한 세일 
void backtrack(int cur_depth, int max_depth, vector<int> &result){
    if(cur_depth == max_depth){
        all_sales.push_back(result);
        return;
    }
    
    for(int i = 0; i<4; i++){
        result[cur_depth] = sales_available[i];
        backtrack(cur_depth + 1, max_depth, result);
    }
}

int get_saled_price(int sale_percent, int price){
    return (100 - sale_percent) * price / 100;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    num_emoticons = emoticons.size();
    
    // 모든 emoticon sale 구하기
    vector<int> result(num_emoticons);
    backtrack(0, num_emoticons, result);
    // for(vector<int> sale : all_sales){
    //     for(int i : sale) cout<<i<<", ";
    //     cout<<endl;
    // }
    
    int max_num_plus = 0, max_revenue = 0;
    // 모든 경우의 수에 대해 각각 연산
    for(vector<int> &all_sale : all_sales){
        
        int num_plus = 0, revenue = 0;
        // 모든 유저에 대해
        for(vector<int> &user : users){
            int buy_ratio = user[0], threshold_price = user[1];
            int buy_sum = 0;
            // 모든 이모티콘에 대해, 할인율보다 높은 건 다 삼
            for(int i = 0; i<num_emoticons; i++){
                if(all_sale[i] >= buy_ratio) buy_sum += get_saled_price(all_sale[i], emoticons[i]);
            }
            // 만약 '일정 가격'이상이라면 플러스에 가입.
            if(buy_sum >= threshold_price){
                buy_sum = 0;
                num_plus++;
            }
            revenue += buy_sum;
        }
        
        if(max_num_plus < num_plus){
            max_num_plus = num_plus;
            max_revenue = revenue;
        }
        if(max_num_plus == num_plus) max_revenue = max(max_revenue, revenue);
    }
    
    return {max_num_plus, max_revenue};
}
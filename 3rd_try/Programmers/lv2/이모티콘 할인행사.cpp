#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num_user, num_emoticon;
vector<vector<int>> users;
vector<int> emoticons;
vector<int> emoticon_sales;
vector<int> ratios;

int max_num_plus = -1;
int max_revenue = -1;

int ratio_applied_price(int origin_price, int ratio){
    return origin_price * (100 - ratio) / 100;
}

// 1
void calculate(){
    vector<int> user_sum(num_user, 0);
    for(int i = 0; i<num_user; i++){
        for(int j = 0; j<num_emoticon; j++){
            if(emoticon_sales[j] >= users[i][0]){
                user_sum[i] += ratio_applied_price(emoticons[j], emoticon_sales[j]);
            }
        }
    }
    
    int num_plus = 0;
    for(int i = 0; i<num_user; i++){
        if(user_sum[i] >= users[i][1]){
            user_sum[i] = 0;
            num_plus++;
        }
    }
    
    int revenue = 0;
    for(int sum : user_sum) revenue += sum;
    
    if(num_plus > max_num_plus){
        max_num_plus = num_plus;
        max_revenue = revenue;
        return;
    }
    else if(num_plus == max_num_plus){
        max_revenue = max(max_revenue, revenue);
        return;
    }
}

// 2
void calculate(){
    int num_plus = 0, revenue = 0;
    for(vector<int> user : users){
        int paid = 0;
        for(int i = 0; i<num_emoticon; i++){
            if(emoticon_sales[i] >= user[0]){
                paid += ratio_applied_price(emoticons[i], emoticon_sales[i]);
            }
        }
        
        if(paid >= user[1]) num_plus++;
        else revenue += paid;
    }
    
    if(num_plus > max_num_plus){
        max_num_plus = num_plus;
        max_revenue = revenue;
        return;
    }
    else if(num_plus == max_num_plus){
        max_revenue = max(max_revenue, revenue);
        return;
    }
}

void backtrack(int cur_depth, int max_depth){
    if(cur_depth == max_depth){
        calculate();
        return;
    }
    
    for(int i = 0; i<4; i++){
        emoticon_sales[cur_depth] = ratios[i];
        backtrack(cur_depth + 1, max_depth);
    }
}

vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons) {
    users = _users; emoticons = _emoticons;
    num_user = users.size(); num_emoticon = emoticons.size();
    emoticon_sales.resize(num_emoticon);
    ratios = {10, 20, 30, 40};
    
    backtrack(0, emoticons.size());
    
    return {max_num_plus, max_revenue};
}

/*
이모티콘 길이가 7이니까 backtrack?
4*7
2*14
2*10 = 1000
16000 * 100
1,600,000
OK
*/
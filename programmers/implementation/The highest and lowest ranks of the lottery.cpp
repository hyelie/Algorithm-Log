// 로또의 최고 순위와 최저 순위

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get_Rank(int matching_numbers){
    int rank = 7 - matching_numbers;
    // 1개 또는 0개가 일치하는 경우, rank는 6, 7이다.
    // 6, 7인 경우 6을, 나머지는 rank를 리턴하면 된다.
    return rank >= 6 ? 6 : rank;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int matched_number = 0, number_zeros = 0;
    
    for(int lotto : lottos){
        if(find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end()) matched_number++;
        if(lotto == 0) number_zeros++;
    }
    
    vector<int> answer;
    answer.push_back(get_Rank(matched_number + number_zeros));
    answer.push_back(get_Rank(matched_number));
    
    return answer;
}

/*

구매한 로또 번호 중 알아볼 수 있는 것과
당첨 번호 6개의 겹치는 것을 먼저 찾는다.
이 값을 matched_number라고 하면

matched_number -> 최소 일치 개수
matched_number + number of zeros -> 최대 일치 개수
이다.


*/
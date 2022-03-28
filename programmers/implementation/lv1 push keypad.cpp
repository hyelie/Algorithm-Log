// 키패드 누르기

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int distance(pii& x, pii& y){
    return abs(x.first - y.first) + abs(x.second - y.second);
}

pii getPosition(int number){
    pii position;
    switch(number){
            case 1:
            case 4:
            case 7:
                position = {number/3, 0};
                break;
            case 3:
            case 6:
            case 9:
                position = {number/3-1, 2};
                break;
            case 2:
            case 5:
            case 8:
                position = {number/3, 1};
                break;
            case 0:
                position = {3, 1};
                break;
    }
    return position;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    bool is_right = (hand == "right") ? true : false;
    
    /*
    1 2 3
    4 5 6
    7 8 9
    * 0 #
    4 * 3의 배열로 생각하자.
    */
    pii left_position = {3, 0}, right_position = {3, 2};
    
    for(int number : numbers){
        switch(number){
            case 1:
            case 4:
            case 7:
                answer += "L";
                left_position = getPosition(number);
                break;
                
            case 3:
            case 6:
            case 9:
                answer += "R";
                right_position = getPosition(number);
                break;
                
            case 2:
            case 5:
            case 8:
            case 0:
                pii number_position = getPosition(number);
                int left_distance = distance(number_position, left_position),
                    right_distance = distance(number_position, right_position);
                
                if(left_distance > right_distance || (left_distance == right_distance && is_right)){
                    answer += "R";
                    right_position = number_position;
                } else if(left_distance < right_distance || (left_distance == right_distance && !is_right)){
                    answer += "L";
                    left_position = number_position;
                }
                break;
                
        }
    }
    
    return answer;
}

// 1 4 7은 왼손
// 3 6 9는 오른손
// 2 5 8 0은 가까운 손으로, 거리 같으면 isRight==true면 right로, false면 left로 함.
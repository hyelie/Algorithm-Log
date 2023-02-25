#include <string>
#include <vector>

using namespace std;


int solution(vector<int> ingredient) {
    int answer = 0;
    for(int i = 0; i<ingredient.size(); i++){
        if(i >= 3 && ingredient[i] == 1 && ingredient[i-1] == 3 && ingredient[i-2] == 2 && ingredient[i-3] == 1){
            ingredient.erase(ingredient.begin() + i); i--;
            ingredient.erase(ingredient.begin() + i); i--;
            ingredient.erase(ingredient.begin() + i); i--;
            ingredient.erase(ingredient.begin() + i); i--;
            answer++;
        }
    }
    
    return answer;
}
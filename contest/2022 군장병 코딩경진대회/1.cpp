#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int h, int k, vector<int> boxes) {
    int answer = 0;
    boxes.push_back(h);
    sort(boxes.begin(), boxes.end(), less<int>());

    int prev_h = 0, cur_h = 0;
    for(int i = 0; i<boxes.size();){
        if(boxes[i] - cur_h <= k){ // 올라갈 수 있으면 ++
			if(i+1 < boxes.size() && boxes[i+1] - cur_h > k){
				answer++;
				prev_h = cur_h;
                cur_h = boxes[i];
			}
            i++;
        }
        else{
			return -1;
        }
    }
    if(cur_h + k < h) return -1;
    return answer;
}
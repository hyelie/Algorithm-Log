// H-index

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int size = citations.size();
    int h_index = -1;
    for(int i = 0; i<size; i++){
        if(citations[i] > i) h_index = max(h_index, i);
    }
    return h_index + 1;
}

// 0 1 3 5 6
// 6 5 3 1 0
// arr[i] > i인 i값들 중 max값을 찾아서 +1하면 됨
// 생각해보자.
// arr[0] > 0은 1번 이상 인용된 논문이 1편 이상
// arr[1] > 1은 2번 이상 인용된 논문이 2편 이상
// arr[2] > 2는 3번 이상 인용된 논문이 3편 이상
// 즉 arr[i] > i는 (i+1)번 이상 인용된 논문이 (i+1)편 이상이라는 것이다. h-index의 조건을 만족한다.
// 이런 i의 최댓값을 찾는다. 이 순간, arr[i+1] <= (i+1)를 만족한다. 그렇지 않다면 i+1이 최댓값이 되었을 것.
// 이 순간은 arr[i+1]부터는 모든 논문이 (i+1)번 이하로 인용되었다는 것이다.
// 따라서, 위 코드가 답이다!
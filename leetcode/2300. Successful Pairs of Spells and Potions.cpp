// Runtime 242 ms Beats 76.16%
// Memory 100.4 MB Beats 12.14%

typedef long long ll;

class Solution {
public:
    int getUpperBoundIndex(vector<ll> &arr, ll target){
        int start = 0, end = arr.size(), mid;
        while(start < end){
            mid = (start + end)/2;
            if(arr[mid] > target){
                end = mid;
            }
            else start = mid+1;
        }
        return end;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // 각 potion에 얼마만큼의 배율이 곱해져야 success가 되는지 배열
        vector<ll> thresholds(potions.size());
        for(int i = 0; i<potions.size(); i++){
            thresholds[i] = success / potions[i] + (success % potions[i] != 0);
        }
        sort(thresholds.begin(), thresholds.end(), less<ll>());

        vector<int> answer(spells.size());
        for(int i = 0; i<spells.size(); i++){
            answer[i] = getUpperBoundIndex(thresholds, (ll)spells[i]);
        }

        return answer;
    }
};
/*
potions[i]에 x를 곱해 success값이 넘는 거의 값을 저장해 두면 되는거 아닐까?
그러면 O(n). 값을 보고, 

1, 2, 3, 4, 5에 7이면
내림차순 정렬하고
5, 4, 3, 2, 1
2, 2, 3, 4, 7
이렇게 저장됨.
-> O(nlogn)

이후, 주어진 어떤 값을 이 배열에서 binary search하고 index를 가져오면 됨. n개니까 O(nlogn)
[upper bound -1]까지의 개수 (== upper bound의 index)을 가져오면 되는거아닌가?
*/
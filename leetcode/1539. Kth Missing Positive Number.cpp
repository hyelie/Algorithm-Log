// Runtime 4 ms Beats 73.18%
// Memory 9.5 MB Beats 94.95%

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end = arr.size();
        while(start < end){
            int mid = (start + end) / 2;
            if(arr[mid] - mid - 1 >= k){ // k가 더 작으므로 앞쪽을 탐색해야 함
                end = mid;
            }
            else start = mid + 1;
        }
        return end + k;
    }
};
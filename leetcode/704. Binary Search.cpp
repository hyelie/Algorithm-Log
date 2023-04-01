class Solution {
public:
    int search(vector<int>& v, int input) {
        int start = 0, end = v.size()-1, mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(v[mid] < input){
            start = mid + 1;
        } else if(v[mid] == input){
            return mid; // found
        } else{
            end = mid - 1;
        }
    }
    return -1; // not found
    }
};
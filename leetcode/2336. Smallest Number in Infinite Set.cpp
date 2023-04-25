// Runtime 73 ms Beats 91.65%
// Memory 35.4 MB Beats 84.48%

class SmallestInfiniteSet {
public:
    int start;
    set<int> s;
    SmallestInfiniteSet() {
        start = 1;
    }

    // start는 infinite의 시작 숫자, pq는 addBack()했을 때 infinite에 있지 않을 때 들어가는 공간
    
    int popSmallest() {
        if(!s.empty()){
            int top = *s.begin(); s.erase(s.begin());
            return top;
        }
        start++;
        return start-1;
    }
    
    void addBack(int num) {
        if(num < start) s.insert(num);
    }
};`
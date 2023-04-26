// Runtime 0 ms Beats 100%
// Memory 5.9 MB Beats 63.10%

class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int temp = 0;
            while(num){
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        return num;
    }
};

// Runtime 7 ms Beats 16.24%
// Memory 6 MB Beats 63.10%

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        return num % 9 == 0 ? 9 : num % 9;
    }
};
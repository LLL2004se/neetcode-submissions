class Solution {
    public: int sumOfSquaresofDigits(int n){
        int sum = 0;

        while (n > 0) {
            int dig = n % 10;
            sum = sum + (dig * dig);
            n = n / 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n,
        fast = n;

        while (fast != 1){
            slow = sumOfSquaresofDigits(slow);
            fast = sumOfSquaresofDigits(sumOfSquaresofDigits(fast));

            if (fast == 1){
                return true;
            }

            if (slow == fast){
                return false;
            }
        }
       return true; 
    }
};
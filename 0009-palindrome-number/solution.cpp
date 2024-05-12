class Solution {
public:
    bool isPalindrome(int number) {
        if (number < 0 || (number != 0 && number % 10 == 0)) {
            return false;
        }
        int reversedHalf = 0;
        while (reversedHalf < number) {
            reversedHalf = reversedHalf * 10 + number % 10;
            number /= 10;
        }
        return number == reversedHalf || number == reversedHalf / 10;
    }
};

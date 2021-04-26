class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        if (x % 10 == 0) {
            return false;
        }
        
        int y = 0;
        while (y < x) {
            y *= 10;
            y += x % 10;
            
            if (y == x) {
                return true;
            }
            
            x /= 10;
            
            if (y == x) {
                return true;
            }
        }
        
        return false;
    }
};

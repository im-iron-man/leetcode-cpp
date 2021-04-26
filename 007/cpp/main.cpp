class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }

        int sign = x > 0 ? 1 : -1;
        x = abs(x);
        
        int y = 0;
        while (x > 0) {
            if (y > INT_MAX / 10) {
                return 0;
            }
            y *= 10;
            y += x % 10;
            if (y < 0) {
                return 0;
            }
            x /= 10;
        }
        
        return sign * y;
    }
};

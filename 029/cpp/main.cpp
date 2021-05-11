class Solution {
private:
    int divide0(int a, int b) {
        int c0 = 0;
        int c = b;
        int n0 = 0;
        int n = 1;
        while (a + c <= 0) {
            c0 = c;
            n0 = n;
            
            if (c > INT_MAX / 2) {
                break;
            }
            
            c <<= 1;
            n <<= 1;
        }
        return n0 == 0 ? 0 : n0 + divide0(a + c0, b);
    }
    
public:
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }
        
        int sign = ((dividend < 0 && divisor >= 0) || (dividend > 0 && divisor < 0)) ? -1 : 1;
        int a = dividend < 0 ? dividend : -dividend;
        int b = abs(divisor);
        
        if (a == INT_MIN && b == 1) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        
        return sign * divide0(a, b);
    }
};

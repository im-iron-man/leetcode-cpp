class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        
        int a = 1;
        int b = 2;
        for (int i = 0; i < n - 2; i++) {
            int t = b;
            b += a;
            a = t;
        }
        return b;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        char c;
        
        int sign = 1;
        for (; idx < s.size(); idx++) {
            c = s[idx];
            if (isspace(c)) {
              continue;  
            } else if (c == '-') {
                sign = -1;
                idx++;
                break;
            } else if (c == '+') {
                idx++;
                break;
            } else if (isdigit(c)) {
                break;
            } else {
                return 0;
            }
        }
        
        int r = 0;
        int r0 = INT_MAX / 10;
        int t;
        int t0 = sign == 1 ? 7 : 8;
        for (; idx < s.size(); idx++) {
            c = s[idx];
            if (isdigit(c)) {
                t = c - '0';
                
                if (r > r0 || (r == r0 && t >= t0)) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                
                r *= 10;
                r += t;
            } else {
                break;
            }
        }
        
        return sign * r;
    }
};

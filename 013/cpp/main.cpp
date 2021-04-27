class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int base = 1;
        int n;
        int n0 = 0;
        int r = 0;
        for (int i = s.size() - 1; i > -1; i--) {
            n = m[s[i]];
            if (n >= n0) {
                r += n;
                n0 = n;
            } else {
                r -= n;
            }
        }
        return r;
    }
};

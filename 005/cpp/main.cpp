class Solution {
public:
    string longestPalindrome(string s) {
        string r = "";
        
        for (int i = 0; i < s.size(); i++) {
            int k = -1;
            for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; j++) {
                k++;
            }
            if (2 * k + 1 > r.size()) {
                r = s.substr(i - k, 2 * k + 1);
            }
        }
        
        for (int i = 0; i < s.size() - 1; i++) {
            int k = 0;
            for (int j = 1; i + 1 - j >= 0 && i + j < s.size() && s[i + 1 - j] == s[i + j]; j++) {
                k++;
            }
            if (2 * k > r.size()) {
                r = s.substr(i + 1 - k, 2 * k);
            }
        }
        
        return r;
    }
};


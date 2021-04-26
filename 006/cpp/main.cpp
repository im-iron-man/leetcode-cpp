class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        } 
        
        string r = "";
        int size = s.size();
        int step1 = numRows - 1;
        int step2 = 2 * step1;

        for (int j = 0; j < size; j += step2) {
            r += s[j];
        }
        
        for (int i = 1; i < step1; i++) {
            for (int j = 0; j - i < size; j += step2) {
                if (j - i >= 0) {
                    r += s[j - i];
                }
                if (j + i < size) {
                    r += s[j + i];
                }
            }
        }
        
        for (int j = step1; j < size; j += step2) {
            r += s[j];
        }
        
        return r;
    }
};

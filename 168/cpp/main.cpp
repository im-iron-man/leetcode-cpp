class Solution {
public:
    string convertToTitle(int columnNumber) {
        string r = "";
        while (columnNumber > 0) {
            columnNumber -= 1;
            r += columnNumber % 26 + 65;
            columnNumber /= 26;
        }
        reverse(r.begin(), r.end());
        return r;
    }
};

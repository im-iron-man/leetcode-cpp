class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return {"()"};
        }
        
        vector<string> result0 = generateParenthesis(n - 1);
        set<string> result1;
        for (string &s: result0) {
            for (int i = 0; i < 2 * n - 1; i++) {
                for (int j = i; j < 2 * n - 1; j++) {
                    result1.insert(s.substr(0, i) + "(" + s.substr(i, j - i) + ")" + s.substr(j));
                }
            }
        }
        
        return vector<string>(result1.begin(), result1.end());
    }
}; 

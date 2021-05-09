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
                for (int j = i + 1; j < 2 * n; j++) {
                    result1.insert(string(s).insert(i, "(").insert(j, ")"));
                }
            }
        }
        
        return vector<string>(result1.begin(), result1.end());
    }
}; 

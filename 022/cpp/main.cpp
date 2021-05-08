class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return {"()"};
        }
        
        vector<string> result0 = generateParenthesis(n - 1);
        map<int, vector<string>> result1;
        for (string &s: result0) {
            int idx = s.find_first_of(')');
            if (result1.find(idx) == result1.end()) {
                result1[idx] = {};
            }
            result1[idx].push_back(s);
        }
        
        vector<string> result;
        
        for (int j = 1; j < n; j++) {
            for (string &s: result1[j]) {
                result.push_back("()" + s);
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (string &s: result1[j]) {
                    result.push_back(s.substr(0, i) + "()" + s.substr(i));
                }
            }
        }
        
        return result;
    }
}; 

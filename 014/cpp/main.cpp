class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        
        string s = "";
        string str = strs[0];
        for (int i = 0; ; i++) {
            if (i >= str.size()) {
                goto END;
            }
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || str[i] != strs[j][i]) {
                    goto END;
                }
            }
            s += str[i];
        }
        
    END:
        return s;
    }
};

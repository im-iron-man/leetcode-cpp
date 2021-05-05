class Solution {
private:
    vector<string> getLetter(char c) {
        switch (c) {
            case '2':
                return {"a", "b", "c"};
            case '3':
                return {"d", "e", "f"};
            case '4':
                return {"g", "h", "i"};
            case '5':
                return {"j", "k", "l"};
            case '6':
                return {"m", "n", "o"};
            case '7':
                return {"p", "q", "r", "s"};
            case '8':
                return {"t", "u", "v"};
            case '9':
                return {"w", "x", "y", "z"};
        }
        return {};
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        
        vector<string> a = getLetter(digits[0]);
        if (digits.size() == 1) {
            return a;
        }
        
        vector<string> b = letterCombinations(digits.substr(1));
        vector<string> result;
        for (string r0: a) {
            for (string r1: b) {
                result.push_back(r0 + r1);
            }
        }
        return result;
    }
};

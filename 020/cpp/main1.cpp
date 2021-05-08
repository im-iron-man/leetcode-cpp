iclass Solution {
private:
    map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
    
public:
    bool isValid(string s) {
        stack<char> r;
        for (char &c: s) {
            if (c == '(' || c == '[' || c == '{') {
                r.push(c);
                continue;
            }
            
            if (r.empty() || r.top() != m[c]) {
                return false;
            }
            
            r.pop();
        }
        return r.empty();
    }
};

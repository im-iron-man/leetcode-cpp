class Solution {
private:
    bool isMatch0(string s, string p) {
        if (p == ".") {
            return s.size() == 1;
        }
        
        if (p == ".*") {
            return true;
        }
        
        if (p.size() == 1) {
            return s == p;
        }
        
        char t = p[0];
        for (char c: s) {
            if (c != t) {
                return false;
            }
        }
        return true;
    }
    
    bool isMatch1(string s, vector<string> ps) {
        if (ps.size() == 0) {
            return s == "";
        }
        
        string p = ps[0];
        vector<string> ps1(ps.begin() + 1, ps.end());
        for (int i = 0; i <= s.size(); i++) {
            if (isMatch0(s.substr(0, i), p) && isMatch1(s.substr(i), ps1)) {
                return true;
            }
        }
        return false;
    }
    
public:
    bool isMatch(string s, string p) {
        vector<string> ps;
        
        int i = p.size() - 1;
        char c;
        while (i > -1) {
            c = p[i--];
            if (c == '*') {
                c = p[i--];
                ps.insert(ps.begin(), string(1, c) + '*');
            } else {
                ps.insert(ps.begin(), string(1, c));
            }
        }
        
        return isMatch1(s, ps);
    }
};

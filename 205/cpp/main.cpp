class Solution {
public:
    bool f(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        map<char, char> m;
        for (int i = 0; i < s.size(); ++i) {
            char c1 = s[i];
            char c2 = t[i];
            
            if (m.find(c1) != m.end() && m[c1] != c2) {
                return false;
            } else {
                m[c1] = c2;
            }
        }
        
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return f(s, t) && f(t, s);
    }
};

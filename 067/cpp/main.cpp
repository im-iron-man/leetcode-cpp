class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0;
        int t = 0;
        string r = "";
        
        while (i < a.size() || i < b.size()) {
            int a1 = (i < a.size() ? a[a.size() - 1 - i] : '0') - '0';
            int a2 = (i < b.size() ? b[b.size() - 1 - i] : '0') - '0';
            t += a1 + a2;
            r.insert(0, std::to_string(t % 2));
            t /= 2;
            i++;
        }
        
        if (t > 0) {
            r.insert(0, std::to_string(t));
        }
        return r;
    }
};

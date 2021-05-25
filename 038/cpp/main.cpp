class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string r = countAndSay(n - 1);
       
        string s = "";
        int i = 0;
        int c = 1;
        for (int j = 1; j < r.size(); j++) {
            if (r[j] == r[i]) {
                c++;
            } else {
                s += std::to_string(c);
                s += r[i];
                
                i = j;
                c = 1;
            }
        }
        
        s += std::to_string(c);
        s += r[i];
        return s;
    }
};

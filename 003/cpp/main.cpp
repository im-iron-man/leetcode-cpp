class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = 0;
        int i = 0;
        int j = 0;
        std::map<char, int> cache;

        for (; j < s.size(); j++) {
            char &c = s[j];
            for (; cache.find(c) != cache.end(); i++) {
                cache.erase(s[i]);
            }
            cache[c] = 1;
            n = std::max(n, (int) cache.size());
        }

        return n;
    }
};


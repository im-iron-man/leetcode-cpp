class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        
        int r = digits[digits.size() - 1] + 1;
        result.insert(result.begin(), r % 10);
        r /= 10;
        
        for (int i = digits.size() - 2; i > -1; i--) {
            r += digits[i];
            result.insert(result.begin(), r % 10);
            r /= 10;
        }
        
        if (r > 0) {
            result.insert(result.begin(), r);
        }
        
        return result;
    }
};

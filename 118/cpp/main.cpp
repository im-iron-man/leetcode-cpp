class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }
        vector<vector<int>> result = generate(numRows - 1);
        vector<int> last0 = result[result.size() - 1];
        vector<int> last1;
        last1.push_back(1);
        for (int i = 0; i < last0.size() - 1; ++i) {
            last1.push_back(last0[i] + last0[i + 1]);
        }
        last1.push_back(1);
        result.push_back(last1);
        return result;
    }
};

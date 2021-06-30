class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {{1}};
        }
        vector<int> last0 = getRow(rowIndex - 1);
        vector<int> last1;
        last1.push_back(1);
        for (int i = 0; i < last0.size() - 1; ++i) {
            last1.push_back(last0[i] + last0[i + 1]);
        }
        last1.push_back(1);
        return last1;
    }
};

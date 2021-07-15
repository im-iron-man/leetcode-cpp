class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int r = numbers[i] + numbers[j];
            if (r < target) {
                i++;
            } else if (r > target) {
                j--;
            } else {
                break;
            }
        }
        return {i + 1, j + 1};
    }
};

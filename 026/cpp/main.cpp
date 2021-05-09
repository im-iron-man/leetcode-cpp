class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        while (idx < nums.size()) {
            if (nums[idx] == nums[idx - 1]) {
                nums.erase(nums.begin() + idx);
            } else {
                idx++;
            }
        }
        return nums.size();
    }
};

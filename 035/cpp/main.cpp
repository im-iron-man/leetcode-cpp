class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        
        while (i < j) {
            int k = i + (j - i) / 2;
            int mid = nums[k];
            if (mid < target) {
                if (i == k) {
                    break;
                }
                i = k; 
            } else if (mid > target) {
                j = k;
            } else {
                return k;
            }
        }
        
        return j;
    }
};

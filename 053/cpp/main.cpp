class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int t = 0;
        int r = nums[0];
        for (int j = 0; j < nums.size(); j++) {
            t += nums[j];
            r = max(r, t);
            t = max(0, t);
            
        }
        return r;
    }
};

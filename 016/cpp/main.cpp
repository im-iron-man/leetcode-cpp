class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            int t1 = nums[i];
            
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int t2 = nums[j];
                int t3 = nums[k];
                int r = t1 + t2 + t3;
                
                if (abs(r - target) < abs(result - target)) {
                    result = r;
                }
                
                if (r == target) {
                    return target;
                } else if (r < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        
        return result;
    }
};

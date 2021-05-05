class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        
        for (int i = 0; i < nums.size(); i++) {
            int t1 = nums[i];
            if (i != 0 && nums[i - 1] == t1) {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int t2 = nums[j];
                int t3 = nums[k];
                
                int r = t2 + t3;
                if (r == -t1) {
                    results.push_back({t1, t2, t3});
                    for (; j < nums.size() && nums[j] == t2; j++);
                    for (; k < nums.size() && nums[k] == t3; k--);
                } else if (r < -t1) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        
        return results;
    }
};

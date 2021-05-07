class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (i != 0 && nums[i - 1] == a) {
                continue;
            }
            
            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                if (j != i + 1 && nums[j - 1] == b) {
                    continue;
                }
                
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    int c = nums[k];
                    int d = nums[l];
                    int t = a + b + c + d - target;
                    if (t == 0) {
                        result.push_back({a, b, c, d});
                        for (; k < nums.size() && nums[k] == c; k++);
                        for (; l > -1 && nums[l] == d; l--);
                    } else if (t < 0) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        
        return result;
    }
};

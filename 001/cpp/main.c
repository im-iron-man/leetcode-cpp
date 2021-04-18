class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> cache;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int t = target - nums[i];
            if (cache.find(t) != cache.end()) {
                return {cache[t], i};
            }
            cache[nums[i]] = i;
        }
        return {};
    }
};

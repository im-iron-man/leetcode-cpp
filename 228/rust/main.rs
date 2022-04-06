impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        if nums.len() == 0 {
            return Vec::new();
        }
        
        let mut start = 0;
        let mut end = 0;
        let mut r = Vec::new();
        for (i, e) in nums.iter().enumerate() {
            if (i == 0) {
                continue;
            }
            
            end = i;
            if (nums[end - 1] + 1 == nums[end]) {
                continue;
            }
            if (start + 1 == end) {
                r.push(nums[start].to_string());
            } else {
                r.push(nums[start].to_string() + "->" + &nums[end - 1].to_string());
            }
            start = i;
        }
        
        if (start == end) {
            r.push(nums[start].to_string());
        } else {
            r.push(nums[start].to_string() + "->" + &nums[end].to_string());
        }
        return r;
    }
}

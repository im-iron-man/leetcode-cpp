impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        use std::collections::HashMap;
        let mut m = HashMap::new();
        for i in 0..nums.len() {
            let n = nums[i];
            if m.contains_key(&n) && (i - m[&n]) as i32 <= k {
                return true;
            } else {
                m.insert(n, i);
            }
        }
        return false;
    }
}

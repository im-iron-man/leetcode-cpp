impl Solution {
    pub fn contains_nearby_almost_duplicate(nums: Vec<i32>, k: i32, t: i32) -> bool {
        use std::cmp;
        let t0 = t as i64;
        for i in 0..nums.len() {
            let t1 = nums[i] as i64;
            for j in (i + 1)..(cmp::min(i + 1 + k as usize, nums.len())) {
                let t2 = nums[j] as i64;
                if (t1 - t2).abs() <= t0 {
                    return true;
                }
            }
        }
        return false;
    }
}

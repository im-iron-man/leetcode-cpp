use std::collections::HashMap;

impl Solution {
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        let mut s = 0;
        let mut m = HashMap::new();
        let mut i = 0;

        for num in nums {
            s += num;
            let r = s % k;
            if let Some(_) = m.get(&r) {
                return true;
            }
            m.entry(i).or_insert(1);
            i = r;
        }
        return false;
    }
}

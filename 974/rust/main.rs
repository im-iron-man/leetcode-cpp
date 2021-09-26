use std::collections::HashMap;

impl Solution {
    pub fn subarrays_div_by_k(nums: Vec<i32>, k: i32) -> i32 {
        let mut s = 0;
        let mut m = HashMap::new();
        let mut n = 0;

        m.insert(0, 1);
        for num in nums {
            s += num;
            let r = (s % k + k) % k;
            if let Some(v) = m.get(&r) {
                n += v;
            }
            let v = m.entry(r).or_insert(0);
            *v += 1;
        }
        return n;
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        let mut s = 0;
        let mut m = HashMap::new();
        let mut n = 0;

        m.insert(0, 1);
        for num in nums {
            if num % 2 == 1 {
                s += 1;
            }
            if let Some(v) = m.get(&(s - k)) {
                n += v;
            }
            let v = m.entry(s).or_insert(0);
            *v += 1;
        }

        return n;
    }
}

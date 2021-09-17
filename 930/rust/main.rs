use std::collections::HashMap;

impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        let mut s = 0;
        let mut m = HashMap::new();
        let mut n = 0;
        
        m.insert(0, 1);
        for num in nums {
            s += num;
            if let Some(v) = m.get(&(s - goal)) {
                n += v;
            }
            let v = m.entry(s).or_insert(0);
            *v += 1;
        }
        
        return n;
    }
}

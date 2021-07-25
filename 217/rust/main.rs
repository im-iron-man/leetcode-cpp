impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        use std::collections::HashSet;
        let mut m = HashSet::new();
        for n in &nums {
            if !m.contains(n) {
                m.insert(n);
            } else {
                return true;
            }
        }
        return false;
    }
}

use std::cmp;

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut min = nums.len() as i32;
        let mut max = 0;
        let mut sum = 0;
        for n in &nums {
            min = cmp::min(min, *n);
            max = cmp::max(max, *n);
            sum += *n;
        }
        if min != 0 {
            return 0;
        }
        if max != nums.len() as i32 {
            return nums.len() as i32;
        }
        return (min + max) * (max - min + 1) / 2 - sum;
    }
}

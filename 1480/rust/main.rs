impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut s = 0;
        let mut r = vec![0; nums.len()];
        
        for (i, num) in nums.iter().enumerate() {
            s += num;
            r[i] = s;
        }
        return r;
    }
}

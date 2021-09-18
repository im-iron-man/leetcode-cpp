impl Solution {
    pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        let mut s = 0;
        let mut m = vec![0; nums.len() + 1];
        let mut n = 0;

        m[0] = 1;
        for num in nums {
            if num % 2 == 1 {
                s += 1;
            }
            if s - k >= 0 {
                n += m[(s - k) as usize];
            }
            m[s as usize] += 1;
        }

        return n;
    }
}

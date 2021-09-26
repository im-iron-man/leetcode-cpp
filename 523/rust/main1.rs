impl Solution {
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        let mut s = 0;
        let mut m = vec![0; k as usize];
        let mut i = 0;

        for num in nums {
            s += num;
            let r = (s % k) as usize;
            if m[r] > 0 {
                return true;
            }
            m[i] = 1;
            i = r;
        }
        return false;
    }
}

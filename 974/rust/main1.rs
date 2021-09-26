impl Solution {
    pub fn subarrays_div_by_k(nums: Vec<i32>, k: i32) -> i32 {
        let mut s = 0;
        let mut m = vec![0; k as usize];
        let mut n = 0;

        m[0] = 1;
        for num in nums {
            s += num;
            let r = ((s % k + k) % k) as usize;
            n += m[r];
            m[r] += 1;
        }
        return n;
    }
}

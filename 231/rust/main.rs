impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n <= 0 {
            return false;
        }
        
        let mut cnt = 0;
        let mut n = n;
        while n > 0 {
            cnt += n & 1;
            n >>= 1;
            if cnt > 1 {
                return false;
            }
        }
        return true;
    }
}

impl Solution {
    pub fn add_digits0(mut num: i32) -> i32 {
        let mut r = 0;
        while (num > 0) {
            r += num % 10;
            num /= 10;
        }
        return r;
    }
    
    pub fn add_digits(num: i32) -> i32 {
        let mut num = num;
        while (num > 9) {
            num = Solution::add_digits0(num);
        }
        return num;
    }
}

// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		let mut a = 0;
        let mut b = n;
        
        while a < b {
            let c = a + (b - a) / 2;
            if self.isBadVersion(c) {
                b = c;
            } else {
                a = c + 1;
            }
        }
        
        return b;
    }
}

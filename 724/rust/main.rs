impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        for num in &nums {
            sum += num;
        }
        // for num in nums.iter() {
        //     sum += num;
        // }
        
        let mut leftSum = 0;
        for i in 0..(nums.len()) {
            if leftSum == sum - leftSum - nums[i] {
                return i as i32;
            }
            leftSum += nums[i];
        }
        // for (i, num) in nums.into_iter().enumerate() {
        //     if leftSum == sum - leftSum - num {
        //         return i as i32;
        //     }
        //     leftSum += num;
        // }
        return -1;
    }
}

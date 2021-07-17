func majorityElement(nums []int) int {
    m, c := nums[0], 1
    for i := 1; i < len(nums); i++ {
        if c == 0 {
            m = nums[i]
            c = 1
        } else if nums[i] == m {
            c++
        } else {
            c--;
        }
    }
    return m
}

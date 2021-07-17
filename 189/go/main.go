func rotate(nums []int, k int) {
    t := nums
    for i := 0; i < k; i++ {
        j := len(t) - 1
        t = append([]int{t[j]}, t[:j]...)
    }
    copy(nums, t)
}

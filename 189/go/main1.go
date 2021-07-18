func rotate2(nums1 []int, nums2 []int) {
    if len(nums1) == 0 || len(nums2) == 0 {
        return
    }
    
    if len(nums1) == len(nums2) {
        for i := 0; i < len(nums1); i++ {
            nums1[i], nums2[i] = nums2[i], nums1[i]
        }
        return
    }
    
    if len(nums1) < len(nums2) {
        idx := len(nums1)
        rotate2(nums1, nums2[:idx])
        rotate2(nums2[:idx], nums2[idx:])
        return
    }
    
    if len(nums1) > len(nums2) {
        idx := len(nums1) - len(nums2)
        rotate2(nums1[idx:], nums2)
        rotate2(nums1[:idx], nums1[idx:])
        return
    }
}

func rotate(nums []int, k int)  {
    idx := len(nums) - k % len(nums)
    rotate2(nums[:idx], nums[idx:])
}

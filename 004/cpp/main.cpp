class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int s = s1 + s2;
        
        int i = 0;
        int j = 0;
        int c;
        vector<int> nums(s);
        for (int k = 0; k < s; k++) {
            if (i == s1) {
                c = nums2[j++];
            } else if (j == s2) {
                c = nums1[i++];
            } else {
                if (nums1[i] <= nums2[j]) {
                    c = nums1[i++];
                } else {
                    c = nums2[j++];
                }
            }
            nums[k] = c;
        }
        
        return (nums[(s - 1) / 2] + nums[s / 2]) / 2.0;
    }
};

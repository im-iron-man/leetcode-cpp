class Solution {
public:
    int maxArea(vector<int>& height) {
        int area0 = 0;
        int area;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            area = (j - i) * min(height[i], height[j]);
            area0 = max(area0, area);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return area0;
    }
};

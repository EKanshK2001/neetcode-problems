/**
 * O(n)
 * 
 * Return the maximum amount of water a container can store.
 * 
 * link: https://leetcode.com/problems/container-with-most-water/
 */

/**
 * @brief this problem takes account of two pointers on the ends of the array because of the widest width.
 * 
 * technicalities:
 * - we shift the lower of the two end pointers (as in their heights) so that we always try to keep a greater area.
 * - during this process we register every maximum area found.
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;

        int l = 0, r = height.size() - 1;                               //starting both pointer at the ends for the widest width.

        while (l < r) {
            int currWater = min(height[l], height[r]) * (r - l);        //length * width = area of rect

            maxWater = max(maxWater, currWater);

            if (height[l] < height[r]) {                                //very nice condition, it basically shifts the bottlenecking height of the two.
                l++;
            }
            else r--;
        }

        return maxWater;
    }
};
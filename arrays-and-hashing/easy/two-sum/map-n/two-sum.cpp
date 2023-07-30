class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int, int> m;

        // for (int i = 0; i < nums.size(); i++) {
        //     m[nums[i]] = i;
        // }

        // for (int i=0; i<nums.size(); i++) {
        //     int complement = target - nums[i];
        //     if (m.find(complement) != m.end() && m[complement] != i) {
        //         return {i, m[complement]};
        //     }
        // }
        // return {};

    //optimised solution 8ms, 10.7mb        O(n), O(n)
        unordered_map <int,int> m;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            //if we find it as a complement, return it (and its index) in array format else keep adding the number with its index in the map
            if (m.find(complement) != m.end() && m[complement] != i) {
                return {i, m[complement]};
            }
            else {
                m[nums[i]] = i;
            }
        }

        return {};  
    }
};
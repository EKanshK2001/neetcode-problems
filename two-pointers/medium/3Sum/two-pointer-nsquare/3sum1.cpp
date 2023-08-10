class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //sorting the vector for solving using two pointer (it works only for sorted arrays)
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int first, second, third;
        int size = nums.size();

        for (first = 0; first < size - 2; first++) {    //this loop only goes uptil the 3rd last element (size - 2) to form triplets

            if (nums[first] > 0) return result;        //this means that if at any point, the first element (the lowest in sorted) itself is greater than 0, then it cant sum to 0 anymore.
            
            if (first > 0 && nums[first] == nums[first-1]) continue;    //skip the loop for the same first element.

            //initializing the second and third elements as the first and last elements of the sublist.
            second = first + 1;
            third = size - 1;

            while (second < third) {                //this loop is only valid if the two pointers dont cross each other
                //the current sum
                int sum = nums[first] + nums[second] + nums[third];

                //the two base cases when sum is less, we increment the lower of two. when sum is greater, we decrememt the greater of two. this impacts the current sum.
                if (sum > 0) {
                    third--;
                }
                else if (sum < 0) {
                    second++;
                }
                else {      //when we find a match
                    result.push_back({nums[first], nums[second], nums[third]});

                    //increment the second element further
                    second++;
                    while (second < third && nums[second] == nums[second - 1]) {        //if the second element is found to be repeated, skip all of them
                        second++;
                    }
                    
                    // while (second < third && nums[third] == nums[third + 1]) {
                    //     third--;
                    // }
                }
            }
        }
        return result;
    }
};
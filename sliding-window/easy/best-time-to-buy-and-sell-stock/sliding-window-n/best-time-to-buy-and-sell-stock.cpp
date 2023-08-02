/*
SLIDING WINDOW (two pointer) 

O(n) where n is the size of array the right pointer traverses

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        //using two pointer or a SLIDING WINDOW
        int l = 0, r = 0;

        while (r < prices.size()) {

            //basically our right pointer is searching for a new low as well as a new high
            if (prices[l] < prices[r]) {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            }

            /*we shift the left pointer to the right pointer as it has found the new low,
            when left was considered the current low. Hence, left is jumping the lowest points
            found by right*/
            else l = r;

            //right is traversing in O(n)
            ++r;
        }
        return maxProfit;
    }
};
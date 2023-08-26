/**
 * O(n) time and O(n) space, where n is the size of array passed.
 * we basically made a hash table, its called bucket sorting here.
 * 
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * 
 * 
 * link: https://leetcode.com/problems/top-k-frequent-elements/
 * 
 */

/*----------Bucket Sort Method O(n) time, O(n) space-----------------*/
/**
 * @brief we code the buckets manually here, where the bucket index will be the frequency of the element it contains.
 * this reduces the size of the bucket array.
 * 
 * the size of buckets array will be determined by the max frequency an element can have in the nums array (which is its size.)
 * that means the bucket array size will be n+1.
 * 
 * in the end the right most elements of buckets array will have the most frequency and we push (k) of them in the result.
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //1. frequency map:
        unordered_map <int, int> freq;
        for (auto &num : nums) {
            freq[num]++;
        }

        //2. Make buckets:
        //where index of bucket is frequency of them elements
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        //the size of buckets will be n+1 (0 based) because it will store the max frequency an element can have in an array of size n

        //3. Put the elements in their bucket:
        for (auto &it : freq) {
            buckets[it.second].push_back(it.first);
        }

        //4. Make result vector:
        // take the k elements needed from right to left of buckets(for higher frequency)
        vector <int> result;
        for (int i = n; i > 0; i--) {
            if (buckets[i].empty()) {
                continue;
            }
            while (!buckets[i].empty() && k > 0) {
                result.push_back(buckets[i].back());        //mind the new methods: .empty(), .back(), .pop_back() -> these are O(1) operations of vectors.
                buckets[i].pop_back();
                k--;
            }
        }

        return result;



        //this solution is not coded yet, its a min heap we just got to know bout it. but also because ive not studied it yet and its time complexity is worse than the above.

        /*--------------min heap----------O(nlogk)-----------------*/
        // unordered_map<int, int> m;
        // for (int i = 0; i < nums.size(); i++) {
        //     m[nums[i]]++;
        // }
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // for (auto it = m.begin(); it != m.end(); it++) {
        //     pq.push({it->second, it->first});
        //     if (pq.size() > k) {
        //         pq.pop();
        //     }
        // }
        // vector<int> result;
        // while (!pq.empty()) {
        //     result.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return result;
    }
};
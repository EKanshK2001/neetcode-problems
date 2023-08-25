/**
 * O(n), O(1) where n is the no. of nodes in the list.
 * floyd's tortoise and hare method.
 * 
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * 
 * link : https://leetcode.com/problems/linked-list-cycle/
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*---------8ms-----O(n) time, O(1) space [FLOYD'S TORTOISE AND HARE METHOD]------*/

        //basic check
        if (head == nullptr) return false;

        //making a slow pointer and fast pointer. slow will traverse 1 distance while fast will traverse 2.
        ListNode *slow = head, *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {  //checking for the limits fast if it reaches null pointer in the way.

            //they will eventually meet if they are in a cycle
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
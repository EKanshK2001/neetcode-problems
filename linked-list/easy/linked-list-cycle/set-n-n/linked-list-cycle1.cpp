/**
 * O(n), O(n) where n is the no. of nodes in the list.
 * set implementation, refer to floyd's tortoise and hare method for O(1) space method which is faster as well.
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
        
        /*------------20ms, O(n) time, O(n) space {set} -------------------------*/
        //set will keep track of visited elements
        set <ListNode*> counter;        //make it of ListNode* type to keep current pointer of ListNode* type
        ListNode *current = head;

        while (current != nullptr) {

            //if node is found in set
            if (counter.find(current) != counter.end()) {
                return true;
            }
        
            //if node is not found yet
            else counter.insert(current);

            //keep incrementing
            current = current->next;
        }
        return false;
    }
};
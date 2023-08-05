/**
 * O(n+m) where n is size of list1 and m is size of list2
 * cant comment on space complexity as it was showing almost the same memory (15mb vs 14.8 or 14.9 mb) used as the splicing algo which used O(1) space but this one does use space at time of node creation
 * however it also frees up the old nodes so maybe that's why
 * 
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 * 
 * link : https://leetcode.com/problems/merge-two-sorted-lists/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0); // Dummy node to simplify the code
        ListNode *current = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = new ListNode(list1->val);   //creates new node (allocation of new memory) each time
                list1 = list1->next;                        //but frees up old nodes as well
            } else {
                current->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            current = current->next;
        }

        // Append any remaining nodes from list1 or list2
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy.next; // Skip the dummy node and return the actual merged list
    }
};
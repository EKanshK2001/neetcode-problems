/**
 * O(n), O(1)
 * 
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

/**
 * @brief Here in this solution, we get to actually not initialize a dummy node or allocate memory, we just have to check a small case and do a minor edit in the traverse condition for right/after.
 * this makes it not go (n+1) nodes apart from previous but n nodes. this means that prev and after actually surround the removal node.
 * 
 * this makes the condition for traversal of after to check for after->next to nullptr. so now we don't stop on null but the node before it.
 * 
 * IMP:
 * it works out for normal lists but a 1 sized list, after will be on null after getting n nodes apart from prev.
 * so we do a check for after to be null (to return head->next) before actually working with after->next later so as to not generate error.
 * rest is all same, make them iterate so that prev is behind the node hence we just make it skip its next node.
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *prev = head, *after = head;

        while (n > 0 && after) {        //make after reach right after the nth node.
            after = after->next;
            n--;
        }

        if (after == nullptr) return head->next;        //check if the list contained only 1 element. in which case return head->next

        while (after->next != nullptr) {    // the condition here is to make after not null but the node before null. slight edit from last code.  L1/prev->L2node->L3/after->null
            prev = prev->next;
            after = after->next;
        }

        prev->next = prev->next->next;

        return head;        //return head this time. (which is edited now)
    }
};
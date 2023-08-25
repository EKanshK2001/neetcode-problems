/**
 * O(n), O(1)
 * 
 * Reorder the list in the following form:
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * link : https://leetcode.com/problems/reorder-list/
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
 * In this problem, we encounter another drawback of singly-linked-list with them not being able to have indices or the ability to reverse traverse.
 * 
 * We solve reordering by taking advantage that we have an alternating pattern between the beginning of the list and the beginning of the end of list.
 * 
 * So we split and reverse the 2nd half of list so that we have forward facing links (so we can actually traverse from the end (right to left)).
 * 
 * 
 * technicalities:
 * - we find the mid point using slow and fast pointers. Similar to floyd's hare and tortoise algorithm. (*fast = head->next in this case with fast and fast->next != null) 
 * - we reverse the second half using the same prev, curr, nxt system. (here prev, second, nxt)
 * - we need to make slow->next (first half) be null so that its not connected to second anymore
 * - merging requires the second to be null as the traverse end condition (same as reversing)
 */

class Solution {
public:
    void reorderList(ListNode* head) {

        //finding mid point with slow, slow->next will be second half
        ListNode *slow = head, *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {      //mind the condition
            slow = slow->next;
            fast = fast->next->next;
        }

        //reversing the second half
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;

        while (second != nullptr) {     //mind the condition
            ListNode *nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
            //this way we'll have prev as the reversed second half
        }


        //merging or splicing
        second = prev;
        ListNode *first = head;
        ListNode *nxt1, *nxt2;

        while (second != nullptr) {     //mind the condition
            nxt1 = first->next;
            nxt2 = second->next;

            first->next = second;
            second->next = nxt1;

            first = nxt1;
            second = nxt2;
        }
    }
};
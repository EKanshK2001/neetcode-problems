/**
 * O(n), O(n)
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
 * Instead of spliting and reversing the 2nd half of list so that we have forward facing links (so we can traverse actually),
 * in this approach we use stacks to get the last element added.
 * 
 * this is possible due to the fact that stacks store the last element added at the top. so they can be accessed easily.
 * 
 * 
 * technicalities:
 * - we only iterate half of the stack because adding them alternatively (duh) in between the current elements
 * - we can also only add the 2nd half of the list but it doesn't make much of a difference. maybe in real life but in leetcode testcases, the difference was minor.
 * - maybe due to the fact that it a linear task and would just add (or subtract) to the time complexity as O(n/2) basically turning out as O(n) in contrast to O(n/2 + n/2) -> O(n)   
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        if ((!head) || (!head->next) || (!head->next->next)) return;

        stack<ListNode*> maStack;
        int size = 0;
        ListNode *curr = head;

        while (curr != nullptr) {
            maStack.push(curr);
            curr = curr->next;
            size++;
        }

        curr = head;

        for (int i = 0; i < size/2; i++) {
            ListNode *backElement = maStack.top();
            maStack.pop();

            backElement->next = curr->next;
            curr->next = backElement;
            curr = curr->next->next;
        }
        
        curr->next = nullptr;       //this is to make the last element have a guaranteed null or end.
    }
};
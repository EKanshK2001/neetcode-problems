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
 * @brief In this solution, we make a dummy node (where we return dummy.next). It's not really needed if we look at the next solution, we can just edit the boundary of loop later but its aight.
 * the prev in this case is just behind the node to be removed, but the right pointer is after 1 more of node after it.
 * 
 * this makes the check for right to be null not necessary tho.
 * 
 * afterwards when we start shifting both pointers 1 step, we get to prev just behind the node to be removed and we do the deed.
 * 
 * technicalities:
 *  - dummy is initialized to be zero and its next pointer pointing to head (so its connected and 1 node before head).
 *  - mind how we make a new list node (dummy) and how we give its 'address' (using &) to a ListNode pointer and how we return [dummy.next] instead of [dummy->next].
 *  - we shift pointers to next with the condition: right to be non null, which means that the moment right is on null, we have placed prev just behind the nth last node (as it was on the dummy node before head).
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0, head);                    //initializing dummy to be behind head

        ListNode *prev = &dummy, *right = head;     

        while (n > 0 && right) {                    //shift right n node apart from the node to be removed (and n+1 from prev)
            right = right->next;
            n--;
        }

        while (right) {                             //whenever right reaches null, the loop breaks leaving prev just behind the nth last node.
            prev = prev->next;
            right = right->next;
        }

        prev->next = prev->next->next;              //we rejoin prev to skip the nth node to the rest of list or to null
        
        return dummy.next;                          //mind that we return dummy(dot)next and not dummy(arrow)next (idk why?)
    }
};
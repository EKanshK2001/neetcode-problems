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
 * @brief In this problem we have to face a small disadvantage of linked list i.e. no indexing. we cant reach a certain node with its index like in an array.
 * we solve this problem be actually using some maths (this solution) or by using two pointer n distance apart (further solutions).
 * 
 * here we first get the size of the list in 1 loop.
 * then we get the index they want to remove with the help of the size we just got.
 * 
 * we get a prev pointer just behind that index and edit its next pointer to next of next.
 * Before actually editing it, we need to perform a null check for the prev pointer, as it might be on null which means that it was a 1 size list.
 * in which case we just edit the next of head to head->next.
 *
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size = 0;
        ListNode *current = head;

        //get size of list
        while (current) {
            size++;
            current = current->next;
        }
        current = head;         //reset current to head

        int change = size - n;  //get the index of removing node (0 based)
        ListNode *prev = nullptr;

        for (int i = 0; i < change; i++) {      //get prev just behind the node
            prev = current;
            current = current->next;
        }

        if (prev) {             //to check if prev itself is on a null, i.e. just 1 element in the list (which will be removed).
          prev->next = current->next;  
        } 
        else head = head->next;

        delete current;     //optional memory leak fix

        return head;
    }
};
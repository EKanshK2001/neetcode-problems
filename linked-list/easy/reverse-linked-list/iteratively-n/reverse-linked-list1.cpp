/*
O(n) time and O(1) space, contrary to O(n) space of recursive call. Here, n is the no. of nodes in the list

Given the head of a singly linked list, reverse the list, and return the reversed list.

link : https://leetcode.com/problems/reverse-linked-list/
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

/*
* basically the prev pointer will keep the turned nodes
* current will traverse to the original current->next with the help of the nxt pointer
* in the end prev will have the new head (i.e. the last node of original)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        //if list is empty or only 1 element is present
        if (head == NULL || head->next == NULL) {
            return head;
        }

        //two of the three pointers prev, current, nxt
        ListNode* current = head;
        ListNode* prev = NULL;


        while (current != NULL){
            //maintaining a next pointer relative to current (to keep track of original node next to current)
            ListNode* nxt = current->next;   
            
            //pointing it back or turning it
            current->next = prev;
            
            //shifting the current and prev pointer by 1 place
            prev = current;
            current = nxt;
        }
        //the last pointer to keep track of the last node (the beginning now) is prev
        return prev;
    }
};
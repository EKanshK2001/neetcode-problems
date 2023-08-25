/**
 * O(n+m) where n is size of list1 and m is size of list2
 * O(1) as splicing
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

    /**
    * this problem requires the splicing of the two lists, so no new memory allocation. But we have discussed the allocation method as well.
    * we just join the merged list to the original lists and start shifting the list so it breaks their links and forms with the new one. 
    * essentialy using O(1) space
    */


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode *mergedList = nullptr;
        //any operations done on current before the next seciton of code will lead to undefined behavior since it's not pointing to a valid node.

        //bug (fixed) : since current is NULL, dereferencing it with current->next will cause undefined behavior or a segmentation fault. 
        //Thats why we have to make the first iteration manually, to make mergedList non-null.
        
        if (list1->val <= list2->val) {
            mergedList = list1;
            list1 = list1->next;
        }
        else {
            mergedList = list2;
            list2 = list2->next;
        }


        ListNode *current = mergedList;

        while(list1 != nullptr && list2 != nullptr) {
            
            //comparing the values of the lists
            if (list1->val <= list2->val) { //this iteration takes equal values as well because it doesn't matter

                //joining of list
                current->next = list1;

                //breaking of link becuase of shifting
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }

            //remember to increment the current pointer
            current = current->next;
        }

        // for (;list1 != nullptr && list2 != nullptr; current = current->next) { //for loops work as well and they make you remember about the current pointer increment 

        //     //comparing the values of the lists
        //     if (list1->val <= list2->val) { //this iteration takes equal values as well because it doesn't matter
        //         current->next = list1; //joining of list
        //         list1 = list1->next; //breaking of link becuase of shifting
        //     }

        //     else {
        //         current->next = list2;
        //         list2 = list2->next;
        //     }
        // }


        //to make the remaining of non-null list join the mergedList
        if (list1 == nullptr) {
            current->next = list2;
        }
        else {
            current->next = list1;
        }

        //not required to return mergedList->next as we did the first iteration manually to make the first node non-null
        return mergedList;

    }
};
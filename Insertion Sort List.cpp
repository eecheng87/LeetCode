/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
  public:
    ListNode *insertionSortList(ListNode *head)
    {
        // start!!

        // for special case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        // declare variable
        ListNode *dummy = (ListNode *)malloc(sizeof(ListNode));
        // let dummy connect to head
        dummy->next = head;

        ListNode *tmp = dummy;
        // this variable is for iterate use
        ListNode *cur = dummy->next;

        // following is for general insert case
        while (cur->next != NULL)
        {

            // this case is for the situation that current node's value is bigger than every node in sorted part of List
            // so we dont need to change its position!!
            if (cur->val < cur->next->val)
            {
                cur = cur->next;
                continue;
            }

            // update tmp(which is flag for sorted part in List)
            while (tmp->next->val < cur->next->val)
            {
                tmp = tmp->next;
            }

            // following is for inserting (linked list operation)
            // first, we use some temporary variable to memorize some specific node
            // it can make our insertion more intuitive!!
            // start!!
            ListNode *tmpNext = tmp->next;
            ListNode *preCur = cur;
            ListNode *curNextNext = cur->next->next;

            tmp->next = cur->next;
            cur->next->next = tmpNext;
            preCur->next = curNextNext;

            // after insert current node into sorted part in List
            // then we need to update our tmp and cur pointer
            tmp = dummy; // let it back to first
            cur = preCur;
        }

        // return answer
        return dummy->next;
        // it is complete for general case, but still not perfect
    }
};
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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *tail;
        ListNode *cur = head;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        dummy->next = head;
        int listNum = 1;
        int curNum = 0;
        while (cur->next != NULL)
        {
            cur = cur->next;
            listNum++;
        }
        if (k % listNum == 0)
            return head;
        tail = cur;
        cur = head;

        while (curNum + k % listNum != listNum)
        {
            curNum++;
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        tail->next = head;

        return cur;
    }
};
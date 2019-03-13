/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//this problem should consider very big input!!!
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{

    struct ListNode *ans = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tmp = ans;
    int carry = 0;
    while (l1 != NULL && l2 != NULL)
    {

        //tmp->val = (l1->val+l2->val+carry)>=10?(l1->val+l2->val+carry)%10:(l1->val+l2->val+carry);
        tmp->val = (l1->val + l2->val);
        /*if(l1->val+l2->val+carry>=10){
            carry = 1;
        }else{
            carry = 0;
        }*/
        l1 = l1->next;
        l2 = l2->next;
        if (l1 != NULL && l2 != NULL)
        {
            tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
    }

    if (l1 == NULL && l2 == NULL)
    {
        tmp->next = NULL;
    }
    else if (l2 == NULL)
    {
        tmp->next = l1;
    }
    else
    {
        tmp->next = l2;
    }

    tmp = ans;
    struct ListNode *flag;
    carry = 0;
    while (tmp->next != NULL)
    {
        if (tmp->val >= 10)
        {
            //tmp->next->val+=tmp->next->val/10;
            tmp->next->val++;
            tmp->val %= 10;
        }
        tmp = tmp->next;
    }
    if (tmp->val >= 10)
    {
        tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->next->val = 1;
        tmp->next->next = NULL;
        tmp->val %= 10;
    }
    return ans;
}
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution
{
public:
    Node *flatten(Node *head)
    {

        Node *ans, *cur = head, *tmp1, *tmp2;

        while (cur != NULL)
        {
            if (cur->child != NULL)
            {
                tmp1 = cur->child;
                for (; tmp1->next != NULL; tmp1 = tmp1->next)
                    ;
                tmp2 = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = NULL;
                tmp1->next = tmp2;
                if (tmp2 != NULL)
                    tmp2->prev = tmp1;
            }
            cur = cur->next;
        }

        return head;
    }
}; /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution
{
public:
    Node *flatten(Node *head)
    {

        Node *ans, *cur = head, *tmp1, *tmp2;

        while (cur != NULL)
        {
            if (cur->child != NULL)
            {
                tmp1 = cur->child;
                for (; tmp1->next != NULL; tmp1 = tmp1->next)
                    ;
                tmp2 = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = NULL;
                tmp1->next = tmp2;
                if (tmp2 != NULL)
                    tmp2->prev = tmp1;
            }
            cur = cur->next;
        }


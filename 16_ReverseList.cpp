# include <iostream>
# include <cstdlib>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)  // struct的构造函数
        : val(x), next(NULL)
    {}
};

void display_list(ListNode* head)
{
    if (head == NULL)
        return;
    for(ListNode* p = head; p != NULL; p = p->next)
        cout << p->val << ' ';
    cout << endl;
}


ListNode* ReverseList_SpaceN(ListNode* pHead)
{
    ListNode *headr = NULL, *p, *node;

    if (pHead == NULL)
        return NULL;

    for (p = pHead; p != NULL; p = p->next)
    {
        node = new ListNode(p->val);
        node->next = headr;
        headr = node;
        node = NULL;
    }

    return headr;
}


ListNode* ReverseList(ListNode* pHead)
{
    ListNode *pre = NULL, *p = pHead, *next;

    if (pHead == NULL)
        return NULL;

    while (p != NULL)
    {
        next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }

    return pre;
}


int main(int argc, char *argv[])
{
    int arr[5] = {1, 5, 3, 4, 2};
    ListNode *node = NULL, *head = NULL, *tail = NULL, *headr = NULL;

    for (int i = 0; i < 5; i++)
    {
        node = new ListNode(arr[i]);

        if (head == NULL)
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
            node = NULL;
        }
    }
    display_list(head);

    headr = ReverseList(head);
    if (headr != NULL)
        display_list(headr);
    else
        cout << "Error." << endl;

    return 0;
}
